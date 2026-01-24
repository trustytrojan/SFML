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
#include <SDL3/SDL.h>

#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include <SFML/System/Vector2.hpp>

#include <cstddef>
#include <memory>
#include <vector>


namespace sf::priv
{
////////////////////////////////////////////////////////////
/// \brief SDL3 Renderer backend for SFML graphics
///
/// This class manages an SDL_Renderer and provides methods
/// to perform rendering operations using SDL3's 2D rendering API
///
////////////////////////////////////////////////////////////
class RendererBackend
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Create a renderer backend for a window
    ///
    /// \param window SDL window to create renderer for
    ///
    /// \return Unique pointer to renderer backend, or nullptr on failure
    ///
    ////////////////////////////////////////////////////////////
    static std::unique_ptr<RendererBackend> create(SDL_Window* window);

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~RendererBackend();

    ////////////////////////////////////////////////////////////
    /// \brief Deleted copy constructor
    ///
    ////////////////////////////////////////////////////////////
    RendererBackend(const RendererBackend&) = delete;

    ////////////////////////////////////////////////////////////
    /// \brief Deleted copy assignment
    ///
    ////////////////////////////////////////////////////////////
    RendererBackend& operator=(const RendererBackend&) = delete;

    ////////////////////////////////////////////////////////////
    /// \brief Get the underlying SDL_Renderer
    ///
    /// \return Pointer to SDL_Renderer
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] SDL_Renderer* getRenderer() const { return m_renderer; }

    ////////////////////////////////////////////////////////////
    /// \brief Clear the render target with a color
    ///
    /// \param color Color to clear with
    ///
    ////////////////////////////////////////////////////////////
    void clear(Color color);

    ////////////////////////////////////////////////////////////
    /// \brief Present the rendered content
    ///
    ////////////////////////////////////////////////////////////
    void present();

    ////////////////////////////////////////////////////////////
    /// \brief Set the viewport for rendering
    ///
    /// \param viewport Viewport rectangle (nullptr for full window)
    ///
    ////////////////////////////////////////////////////////////
    void setViewport(const SDL_Rect* viewport);

    ////////////////////////////////////////////////////////////
    /// \brief Set the clip rectangle
    ///
    /// \param clipRect Clip rectangle (nullptr for no clipping)
    ///
    ////////////////////////////////////////////////////////////
    void setClipRect(const SDL_Rect* clipRect);

    ////////////////////////////////////////////////////////////
    /// \brief Set the blend mode
    ///
    /// \param mode SFML blend mode to use
    ///
    ////////////////////////////////////////////////////////////
    void setBlendMode(const BlendMode& mode);

    ////////////////////////////////////////////////////////////
    /// \brief Draw primitives using vertices
    ///
    /// \param vertices    Array of SFML vertices
    /// \param vertexCount Number of vertices
    /// \param type        Type of primitives to draw
    /// \param texture     Optional texture to use (nullptr for colored primitives)
    ///
    ////////////////////////////////////////////////////////////
    void drawPrimitives(const Vertex*  vertices,
                        std::size_t    vertexCount,
                        PrimitiveType  type,
                        SDL_Texture*   texture = nullptr);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a texture
    ///
    /// \param texture Texture to draw
    /// \param srcRect Source rectangle (nullptr for entire texture)
    /// \param dstRect Destination rectangle (nullptr for entire target)
    ///
    ////////////////////////////////////////////////////////////
    void drawTexture(SDL_Texture* texture, const SDL_FRect* srcRect, const SDL_FRect* dstRect);

private:
    ////////////////////////////////////////////////////////////
    /// \brief Private constructor
    ///
    /// \param renderer SDL_Renderer to manage
    ///
    ////////////////////////////////////////////////////////////
    explicit RendererBackend(SDL_Renderer* renderer);

    ////////////////////////////////////////////////////////////
    /// \brief Convert SFML BlendMode to SDL blend mode
    ///
    /// \param mode SFML blend mode
    ///
    /// \return SDL blend mode
    ///
    ////////////////////////////////////////////////////////////
    [[nodiscard]] static SDL_BlendMode convertBlendMode(const BlendMode& mode);

    ////////////////////////////////////////////////////////////
    /// \brief Convert SFML vertices to SDL vertices
    ///
    /// \param vertices    SFML vertices
    /// \param vertexCount Number of vertices
    ///
    ////////////////////////////////////////////////////////////
    void convertVertices(const Vertex* vertices, std::size_t vertexCount);

    ////////////////////////////////////////////////////////////
    /// \brief Get indices for primitive type
    ///
    /// \param type        Primitive type
    /// \param vertexCount Number of vertices
    ///
    ////////////////////////////////////////////////////////////
    void generateIndices(PrimitiveType type, std::size_t vertexCount);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    SDL_Renderer*           m_renderer;      //!< SDL renderer handle
    std::vector<SDL_Vertex> m_sdlVertices;   //!< Converted SDL vertices
    std::vector<int>        m_indices;       //!< Triangle indices
};

} // namespace sf::priv
