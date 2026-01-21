////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2025 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/JoystickImpl.hpp>

#include <SDL3/SDL.h>

#include <cstring>

namespace sf::priv
{
////////////////////////////////////////////////////////////
void JoystickImpl::initialize()
{
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
}


////////////////////////////////////////////////////////////
void JoystickImpl::cleanup()
{
    SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
}


////////////////////////////////////////////////////////////
bool JoystickImpl::isConnected(unsigned int index)
{
    int             count     = 0;
    SDL_JoystickID* joysticks = SDL_GetJoysticks(&count);
    if (!joysticks)
        return false;

    bool connected = (static_cast<int>(index) < count);
    SDL_free(joysticks);
    return connected;
}


////////////////////////////////////////////////////////////
bool JoystickImpl::open(unsigned int index)
{
    int             count     = 0;
    SDL_JoystickID* joysticks = SDL_GetJoysticks(&count);
    if (!joysticks)
        return false;

    if (static_cast<int>(index) < count)
    {
        m_joystick = SDL_OpenJoystick(joysticks[index]);
    }

    SDL_free(joysticks);
    return m_joystick != nullptr;
}


////////////////////////////////////////////////////////////
void JoystickImpl::close()
{
    if (m_joystick)
    {
        SDL_CloseJoystick(m_joystick);
        m_joystick = nullptr;
    }
}


////////////////////////////////////////////////////////////
JoystickCaps JoystickImpl::getCapabilities() const
{
    JoystickCaps caps;

    if (m_joystick)
    {
        caps.buttonCount = static_cast<unsigned int>(SDL_GetNumJoystickButtons(m_joystick));

        int axisCount = SDL_GetNumJoystickAxes(m_joystick);
        for (int i = 0; i < axisCount && i < static_cast<int>(Joystick::AxisCount); ++i)
            caps.axes[static_cast<Joystick::Axis>(i)] = true;
    }

    return caps;
}


////////////////////////////////////////////////////////////
Joystick::Identification JoystickImpl::getIdentification() const
{
    Joystick::Identification id;

    if (m_joystick)
    {
        const char* name = SDL_GetJoystickName(m_joystick);
        id.name          = name ? String::fromUtf8(name, name + std::strlen(name)) : "Unknown Joystick";
        id.vendorId      = SDL_GetJoystickVendor(m_joystick);
        id.productId     = SDL_GetJoystickProduct(m_joystick);
    }

    return id;
}


////////////////////////////////////////////////////////////
JoystickState JoystickImpl::update()
{
    JoystickState state;

    if (m_joystick)
    {
        state.connected = true;

        int buttonCount = SDL_GetNumJoystickButtons(m_joystick);
        for (int i = 0; i < buttonCount && i < static_cast<int>(Joystick::ButtonCount); ++i)
            state.buttons[static_cast<std::size_t>(i)] = (SDL_GetJoystickButton(m_joystick, i) != 0);

        int axisCount = SDL_GetNumJoystickAxes(m_joystick);
        for (int i = 0; i < axisCount && i < static_cast<int>(Joystick::AxisCount); ++i)
        {
            float value                                = static_cast<float>(SDL_GetJoystickAxis(m_joystick, i));
            state.axes[static_cast<Joystick::Axis>(i)] = (value / 32767.f) * 100.f;
        }
    }

    return state;
}

} // namespace sf::priv
