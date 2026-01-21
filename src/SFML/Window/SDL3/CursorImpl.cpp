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
#include <SFML/Window/SDL3/CursorImpl.hpp>
#include <SFML/Window/SDL3/Utils.hpp>

#include <SDL3/SDL.h>

namespace sf::priv
{
////////////////////////////////////////////////////////////
CursorImpl::~CursorImpl()
{
    if (m_cursor)
        SDL_DestroyCursor(m_cursor);
}


////////////////////////////////////////////////////////////
bool CursorImpl::loadFromPixels(const std::uint8_t* pixels, Vector2u size, Vector2u hotspot)
{
    ensureSdlVideoInit();

    if (m_cursor)
        SDL_DestroyCursor(m_cursor);

    SDL_Surface* surface = SDL_CreateSurfaceFrom(static_cast<int>(size.x),
                                                 static_cast<int>(size.y),
                                                 SDL_PIXELFORMAT_ABGR8888,
                                                 const_cast<std::uint8_t*>(pixels),
                                                 static_cast<int>(size.x * 4));
    if (!surface)
        return false;

    m_cursor = SDL_CreateColorCursor(surface, static_cast<int>(hotspot.x), static_cast<int>(hotspot.y));
    SDL_DestroySurface(surface);

    return m_cursor != nullptr;
}


////////////////////////////////////////////////////////////
bool CursorImpl::loadFromSystem(Cursor::Type type)
{
    ensureSdlVideoInit();

    if (m_cursor)
        SDL_DestroyCursor(m_cursor);

    SDL_SystemCursor sdlType = SDL_SYSTEM_CURSOR_DEFAULT;
    // clang-format off
    switch (type)
    {
        case Cursor::Type::Arrow:                  sdlType = SDL_SYSTEM_CURSOR_DEFAULT; break;
        case Cursor::Type::ArrowWait:              sdlType = SDL_SYSTEM_CURSOR_PROGRESS; break;
        case Cursor::Type::Wait:                   sdlType = SDL_SYSTEM_CURSOR_WAIT; break;
        case Cursor::Type::Text:                   sdlType = SDL_SYSTEM_CURSOR_TEXT; break;
        case Cursor::Type::Hand:                   sdlType = SDL_SYSTEM_CURSOR_POINTER; break;
        case Cursor::Type::SizeHorizontal:         sdlType = SDL_SYSTEM_CURSOR_EW_RESIZE; break;
        case Cursor::Type::SizeVertical:           sdlType = SDL_SYSTEM_CURSOR_NS_RESIZE; break;
        case Cursor::Type::SizeTopLeftBottomRight: sdlType = SDL_SYSTEM_CURSOR_NWSE_RESIZE; break;
        case Cursor::Type::SizeBottomLeftTopRight: sdlType = SDL_SYSTEM_CURSOR_NESW_RESIZE; break;
        case Cursor::Type::SizeLeft:               sdlType = SDL_SYSTEM_CURSOR_W_RESIZE; break;
        case Cursor::Type::SizeRight:              sdlType = SDL_SYSTEM_CURSOR_E_RESIZE; break;
        case Cursor::Type::SizeTop:                sdlType = SDL_SYSTEM_CURSOR_N_RESIZE; break;
        case Cursor::Type::SizeBottom:             sdlType = SDL_SYSTEM_CURSOR_S_RESIZE; break;
        case Cursor::Type::SizeTopLeft:            sdlType = SDL_SYSTEM_CURSOR_NW_RESIZE; break;
        case Cursor::Type::SizeTopRight:           sdlType = SDL_SYSTEM_CURSOR_NE_RESIZE; break;
        case Cursor::Type::SizeBottomLeft:         sdlType = SDL_SYSTEM_CURSOR_SW_RESIZE; break;
        case Cursor::Type::SizeBottomRight:        sdlType = SDL_SYSTEM_CURSOR_SE_RESIZE; break;
        case Cursor::Type::SizeAll:                sdlType = SDL_SYSTEM_CURSOR_MOVE; break;
        case Cursor::Type::Cross:                  sdlType = SDL_SYSTEM_CURSOR_CROSSHAIR; break;
        case Cursor::Type::Help:                   sdlType = SDL_SYSTEM_CURSOR_DEFAULT; break;
        case Cursor::Type::NotAllowed:             sdlType = SDL_SYSTEM_CURSOR_NOT_ALLOWED; break;
    }
    // clang-format on

    m_cursor = SDL_CreateSystemCursor(sdlType);
    return m_cursor != nullptr;
}

} // namespace sf::priv
