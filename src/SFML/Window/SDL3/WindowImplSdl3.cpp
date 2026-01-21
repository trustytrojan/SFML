////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2026 trustytrojan (t@trustytrojan.dev)
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
#include <SFML/Window/SDL3/Utils.hpp>
#include <SFML/Window/SDL3/WindowImplSdl3.hpp>

#include <SFML/System/Err.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Utf.hpp>

#include <SDL3/SDL.h>
#include <SDL3/SDL_keycode.h>
#include <ostream>


namespace sf::priv
{
////////////////////////////////////////////////////////////
WindowImplSdl3::WindowImplSdl3(WindowHandle /*handle*/)
{
    ensureSdlVideoInit();

    // SDL3 doesn't support creating a window from an existing handle directly
    // This is a limitation of the SDL3 backend
    err() << "Creating window from handle is not supported with SDL3 backend" << std::endl;

    // Create a default window as fallback
    m_window = SDL_CreateWindow("SFML Window", 800, 600, 0);
    if (!m_window)
    {
        err() << "Failed to create SDL3 window from handle: " << SDL_GetError() << std::endl;
    }
}


////////////////////////////////////////////////////////////
WindowImplSdl3::WindowImplSdl3(VideoMode mode, const String& title, std::uint32_t style, State state, const ContextSettings& settings)
{
    // Initialize SDL if not already initialized
    ensureSdlVideoInit();

    // Apply settings BEFORE window creation for OpenGL windows
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, static_cast<int>(settings.depthBits));
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, static_cast<int>(settings.stencilBits));
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, settings.antiAliasingLevel > 0 ? 1 : 0);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, static_cast<int>(settings.antiAliasingLevel));
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, static_cast<int>(settings.majorVersion));
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, static_cast<int>(settings.minorVersion));
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        (settings.attributeFlags & ContextSettings::Core) ? SDL_GL_CONTEXT_PROFILE_CORE
                                                                          : SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS,
                        (settings.attributeFlags & ContextSettings::Debug) ? SDL_GL_CONTEXT_DEBUG_FLAG : 0);

    // Convert title to UTF-8
    std::string utf8Title;
    Utf<32>::toUtf8(title.begin(), title.end(), std::back_inserter(utf8Title));

    // Create the window with appropriate flags
    const SDL_WindowFlags flags = getSDLWindowFlags(style, state);

    m_window = SDL_CreateWindow(utf8Title.c_str(), static_cast<int>(mode.size.x), static_cast<int>(mode.size.y), flags);

    if (!m_window)
    {
        err() << "Failed to create SDL3 window: " << SDL_GetError() << std::endl;
        return;
    }

    // Set window position if not fullscreen
    if (state != State::Fullscreen)
    {
        SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }
}


////////////////////////////////////////////////////////////
WindowImplSdl3::~WindowImplSdl3()
{
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
    }
}


////////////////////////////////////////////////////////////
WindowHandle WindowImplSdl3::getNativeHandle() const
{
    return m_window;
}


////////////////////////////////////////////////////////////
Vector2i WindowImplSdl3::getPosition() const
{
    if (!m_window)
        return {};

    int x = 0;
    int y = 0;
    SDL_GetWindowPosition(m_window, &x, &y);
    return {x, y};
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setPosition(Vector2i position)
{
    if (m_window)
    {
        SDL_SetWindowPosition(m_window, position.x, position.y);
    }
}


////////////////////////////////////////////////////////////
Vector2u WindowImplSdl3::getSize() const
{
    if (!m_window)
        return {};

    int width  = 0;
    int height = 0;
    SDL_GetWindowSize(m_window, &width, &height);
    return {static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setSize(Vector2u size)
{
    if (m_window)
    {
        SDL_SetWindowSize(m_window, static_cast<int>(size.x), static_cast<int>(size.y));
    }
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setMinimumSize(const std::optional<Vector2u>& minimumSize)
{
    WindowImpl::setMinimumSize(minimumSize);

    if (m_window)
    {
        if (minimumSize.has_value())
        {
            SDL_SetWindowMinimumSize(m_window, static_cast<int>(minimumSize->x), static_cast<int>(minimumSize->y));
        }
        else
        {
            SDL_SetWindowMinimumSize(m_window, 0, 0);
        }
    }
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setMaximumSize(const std::optional<Vector2u>& maximumSize)
{
    WindowImpl::setMaximumSize(maximumSize);

    if (m_window)
    {
        if (maximumSize.has_value())
        {
            SDL_SetWindowMaximumSize(m_window, static_cast<int>(maximumSize->x), static_cast<int>(maximumSize->y));
        }
        else
        {
            SDL_SetWindowMaximumSize(m_window, 0, 0);
        }
    }
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setTitle(const String& title)
{
    if (m_window)
    {
        std::string utf8Title;
        Utf<32>::toUtf8(title.begin(), title.end(), std::back_inserter(utf8Title));
        SDL_SetWindowTitle(m_window, utf8Title.c_str());
    }
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setIcon(Vector2u size, const std::uint8_t* pixels)
{
    if (!m_window || !pixels)
        return;

    // Create an SDL surface from the pixel data
    SDL_Surface* surface = SDL_CreateSurfaceFrom(static_cast<int>(size.x),
                                                 static_cast<int>(size.y),
                                                 SDL_PIXELFORMAT_RGBA32,
                                                 const_cast<std::uint8_t*>(pixels),
                                                 static_cast<int>(size.x * 4));
    if (surface)
    {
        SDL_SetWindowIcon(m_window, surface);
        SDL_DestroySurface(surface);
    }
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setVisible(bool visible)
{
    if (m_window)
    {
        if (visible)
            SDL_ShowWindow(m_window);
        else
            SDL_HideWindow(m_window);
    }
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setMouseCursorVisible(bool visible)
{
    m_mouseVisible = visible;
    if (visible)
        SDL_ShowCursor();
    else
        SDL_HideCursor();
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setMouseCursorGrabbed(bool grabbed)
{
    if (m_window)
    {
        m_mouseGrabbed = grabbed;
        SDL_SetWindowMouseGrab(m_window, grabbed);
    }
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setMouseCursor(const CursorImpl& /*cursor*/)
{
    // SDL3 cursor implementation would require additional cursor conversion
    // For now, this is a stub
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::setKeyRepeatEnabled(bool enabled)
{
    m_keyRepeatEnabled = enabled;
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::requestFocus()
{
    if (m_window)
    {
        SDL_RaiseWindow(m_window);
    }
}


////////////////////////////////////////////////////////////
bool WindowImplSdl3::hasFocus() const
{
    if (!m_window)
        return false;

    const SDL_WindowFlags flags = SDL_GetWindowFlags(m_window);
    return (flags & SDL_WINDOW_INPUT_FOCUS) != 0;
}


////////////////////////////////////////////////////////////
void WindowImplSdl3::processEvents()
{
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent))
    {
        if (auto event = convertEvent(sdlEvent))
        {
            pushEvent(*event);
        }
    }
}


////////////////////////////////////////////////////////////
std::optional<Event> WindowImplSdl3::convertEvent(const SDL_Event& sdlEvent)
{
    // Filter events for this window
    if (sdlEvent.type >= SDL_EVENT_WINDOW_FIRST && sdlEvent.type <= SDL_EVENT_WINDOW_LAST)
    {
        if (sdlEvent.window.windowID != SDL_GetWindowID(m_window))
            return std::nullopt;
    }

    switch (sdlEvent.type)
    {
        case SDL_EVENT_QUIT:
            return Event::Closed{};

        case SDL_EVENT_WINDOW_RESIZED:
            return Event::Resized{
                {static_cast<unsigned int>(sdlEvent.window.data1), static_cast<unsigned int>(sdlEvent.window.data2)}};

        case SDL_EVENT_WINDOW_FOCUS_GAINED:
            return Event::FocusGained{};

        case SDL_EVENT_WINDOW_FOCUS_LOST:
            return Event::FocusLost{};

        case SDL_EVENT_KEY_DOWN:
        {
            // Handle key repeat
            if (!m_keyRepeatEnabled && sdlEvent.key.repeat)
                return std::nullopt;

            return Event::KeyPressed{sdlKeyToSfml(sdlEvent.key.key),
                                     sdlScancodeToSfml(sdlEvent.key.scancode),
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_ALT),
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_CTRL),
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_SHIFT),
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_GUI)};
        }

        case SDL_EVENT_KEY_UP:
        {
            return Event::KeyReleased{sdlKeyToSfml(sdlEvent.key.key),
                                      sdlScancodeToSfml(sdlEvent.key.scancode),
                                      static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_ALT),
                                      static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_CTRL),
                                      static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_SHIFT),
                                      static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_GUI)};
        }

        case SDL_EVENT_TEXT_INPUT:
        {
            // Convert UTF-8 text to UTF-32
            std::u32string utf32Text;
            Utf<8>::toUtf32(sdlEvent.text.text,
                            sdlEvent.text.text + ::strlen(sdlEvent.text.text),
                            std::back_inserter(utf32Text));

            for (char32_t codepoint : utf32Text)
            {
                pushEvent(Event::TextEntered{codepoint});
            }
            return std::nullopt; // Already pushed events
        }

        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            return Event::MouseButtonPressed{sdlMouseButtonToSfml(sdlEvent.button.button),
                                             {static_cast<int>(sdlEvent.button.x), static_cast<int>(sdlEvent.button.y)}};

        case SDL_EVENT_MOUSE_BUTTON_UP:
            return Event::MouseButtonReleased{sdlMouseButtonToSfml(sdlEvent.button.button),
                                              {static_cast<int>(sdlEvent.button.x), static_cast<int>(sdlEvent.button.y)}};

        case SDL_EVENT_MOUSE_MOTION:
            return Event::MouseMoved{{static_cast<int>(sdlEvent.motion.x), static_cast<int>(sdlEvent.motion.y)}};

        case SDL_EVENT_MOUSE_WHEEL:
        {
            // SDL3 uses float for wheel movement
            const float delta = sdlEvent.wheel.y;
            return Event::MouseWheelScrolled{Mouse::Wheel::Vertical,
                                             delta,
                                             {static_cast<int>(sdlEvent.wheel.mouse_x),
                                              static_cast<int>(sdlEvent.wheel.mouse_y)}};
        }

        case SDL_EVENT_WINDOW_MOUSE_ENTER:
            return Event::MouseEntered{};

        case SDL_EVENT_WINDOW_MOUSE_LEAVE:
            return Event::MouseLeft{};

        default:
            return std::nullopt;
    }
}


////////////////////////////////////////////////////////////
SDL_WindowFlags WindowImplSdl3::getSDLWindowFlags(std::uint32_t style, State state)
{
    SDL_WindowFlags flags = 0;

    if (state == State::Fullscreen)
    {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    else
    {
        if (style & Style::Titlebar)
        {
            // Default window has titlebar
        }
        if (style & Style::Resize)
        {
            flags |= SDL_WINDOW_RESIZABLE;
        }
        if (style & Style::Close)
        {
            // SDL3 windows can be closed by default
        }
    }

    // Always create with OpenGL support for SFML
    flags |= SDL_WINDOW_OPENGL;

    return flags;
}

} // namespace sf::priv
