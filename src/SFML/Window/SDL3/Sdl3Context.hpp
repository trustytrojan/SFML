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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/GlContext.hpp>

#include <SDL3/SDL.h>

namespace sf::priv
{
////////////////////////////////////////////////////////////
/// \brief SDL3 implementation of OpenGL contexts
///
////////////////////////////////////////////////////////////
class Sdl3Context : public GlContext
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Create a new default context
    ///
    /// \param shared Context to share the new one with (can be a null pointer)
    ///
    ////////////////////////////////////////////////////////////
    explicit Sdl3Context(Sdl3Context* shared);

    ////////////////////////////////////////////////////////////
    /// \brief Create a new context attached to a window
    ///
    /// \param shared       Context to share the new one with
    /// \param settings     Creation parameters
    /// \param owner        Pointer to the owner window
    /// \param bitsPerPixel Pixel depth, in bits per pixel
    ///
    ////////////////////////////////////////////////////////////
    Sdl3Context(Sdl3Context* shared, const ContextSettings& settings, const WindowImpl& owner, unsigned int bitsPerPixel);

    ////////////////////////////////////////////////////////////
    /// \brief Create a new context that embeds its own rendering target
    ///
    /// \param shared   Context to share the new one with
    /// \param settings Creation parameters
    /// \param size     Back buffer width and height, in pixels
    ///
    ////////////////////////////////////////////////////////////
    Sdl3Context(Sdl3Context* shared, const ContextSettings& settings, Vector2u size);

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~Sdl3Context() override;

    ////////////////////////////////////////////////////////////
    /// \brief Get the address of an OpenGL function
    ///
    /// \param name Name of the function to get the address of
    ///
    /// \return Address of the OpenGL function, 0 on failure
    ///
    ////////////////////////////////////////////////////////////
    static GlFunctionPointer getFunction(const char* name);

    ////////////////////////////////////////////////////////////
    /// \brief Activate the context as the current target for rendering
    ///
    /// \param current Whether to make the context current or no longer current
    ///
    /// \return `true` on success, `false` if any error happened
    ///
    ////////////////////////////////////////////////////////////
    bool makeCurrent(bool current) override;

    ////////////////////////////////////////////////////////////
    /// \brief Display what has been rendered to the context so far
    ///
    ////////////////////////////////////////////////////////////
    void display() override;

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable vertical synchronization
    ///
    /// \param enabled `true` to enable, `false` to disable
    ///
    ////////////////////////////////////////////////////////////
    void setVerticalSyncEnabled(bool enabled) override;

private:
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    SDL_Window*   m_window{nullptr};   //!< SDL window handle
    SDL_GLContext m_context{nullptr};  //!< SDL OpenGL context handle
    bool          m_ownsWindow{false}; //!< Does the context own the window?
};

} // namespace sf::priv
