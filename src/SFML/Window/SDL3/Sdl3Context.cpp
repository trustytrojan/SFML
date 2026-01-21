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
#include <SFML/Window/SDL3/Sdl3Context.hpp>
#include <SFML/Window/WindowImpl.hpp>

#include <SFML/System/Err.hpp>

#include <ostream>


namespace
{
void updateSettings(sf::ContextSettings& settings)
{
    int value = 0;
    SDL_GL_GetAttribute(SDL_GL_DEPTH_SIZE, &value);
    settings.depthBits = static_cast<unsigned int>(value);

    SDL_GL_GetAttribute(SDL_GL_STENCIL_SIZE, &value);
    settings.stencilBits = static_cast<unsigned int>(value);

    SDL_GL_GetAttribute(SDL_GL_MULTISAMPLESAMPLES, &value);
    settings.antiAliasingLevel = static_cast<unsigned int>(value);

    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);
    settings.majorVersion = static_cast<unsigned int>(value);

    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &value);
    settings.minorVersion = static_cast<unsigned int>(value);

    int flags = 0;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_FLAGS, &flags);
    settings.attributeFlags = sf::ContextSettings::Attribute::Default;
    if (flags & SDL_GL_CONTEXT_DEBUG_FLAG)
        settings.attributeFlags |= sf::ContextSettings::Attribute::Debug;

    int profile = 0;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, &profile);
    if (profile & SDL_GL_CONTEXT_PROFILE_CORE)
        settings.attributeFlags |= sf::ContextSettings::Attribute::Core;
}
} // namespace


namespace sf::priv
{
////////////////////////////////////////////////////////////
Sdl3Context::Sdl3Context(Sdl3Context* shared)
{
    if (shared)
        SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);

    // Create a hidden window for the context
    m_window = SDL_CreateWindow("", 1, 1, SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL);
    if (!m_window)
    {
        err() << "Failed to create hidden window for SDL3 context" << std::endl;
        return;
    }
    m_ownsWindow = true;

    m_context = SDL_GL_CreateContext(m_window);
    updateSettings(m_settings);
}


////////////////////////////////////////////////////////////
Sdl3Context::Sdl3Context(Sdl3Context* shared, const ContextSettings& settings, const WindowImpl& owner, unsigned int)
{
    m_window     = static_cast<SDL_Window*>(owner.getNativeHandle());
    m_ownsWindow = false;

    // Apply settings
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

    if (shared)
        SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);

    m_context = SDL_GL_CreateContext(m_window);
    updateSettings(m_settings);
}


////////////////////////////////////////////////////////////
Sdl3Context::Sdl3Context(Sdl3Context* shared, const ContextSettings& settings, Vector2u size)
{
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

    m_window = SDL_CreateWindow("", static_cast<int>(size.x), static_cast<int>(size.y), SDL_WINDOW_HIDDEN | SDL_WINDOW_OPENGL);
    m_ownsWindow = true;

    if (shared)
        SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);

    m_context = SDL_GL_CreateContext(m_window);
    updateSettings(m_settings);
}


////////////////////////////////////////////////////////////
Sdl3Context::~Sdl3Context()
{
    if (m_context)
        SDL_GL_DestroyContext(m_context);

    if (m_window && m_ownsWindow)
        SDL_DestroyWindow(m_window);
}


////////////////////////////////////////////////////////////
GlFunctionPointer Sdl3Context::getFunction(const char* name)
{
    return reinterpret_cast<GlFunctionPointer>(SDL_GL_GetProcAddress(name));
}


////////////////////////////////////////////////////////////
bool Sdl3Context::makeCurrent(bool current)
{
    if (current)
        return SDL_GL_MakeCurrent(m_window, m_context);

    return SDL_GL_MakeCurrent(m_window, nullptr);
}


////////////////////////////////////////////////////////////
void Sdl3Context::display()
{
    if (m_window)
        SDL_GL_SwapWindow(m_window);
}


////////////////////////////////////////////////////////////
void Sdl3Context::setVerticalSyncEnabled(bool enabled)
{
    SDL_GL_SetSwapInterval(enabled ? 1 : 0);
}

} // namespace sf::priv
