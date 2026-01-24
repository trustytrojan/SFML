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
#include <SFML/Graphics/SDL3/RendererBackend.hpp>

#include <SFML/System/Err.hpp>

#include <algorithm>


namespace sf::priv
{
////////////////////////////////////////////////////////////
std::unique_ptr<RendererBackend> RendererBackend::create(SDL_Window* window)
{
    if (!window)
    {
        err() << "Cannot create RendererBackend: window is null" << std::endl;
        return nullptr;
    }

    // Create SDL renderer with accelerated rendering and VSync
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer)
    {
        err() << "Failed to create SDL_Renderer: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // Enable alpha blending by default
    if (!SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND))
    {
        err() << "Failed to set blend mode: " << SDL_GetError() << std::endl;
    }

    return std::unique_ptr<RendererBackend>(new RendererBackend(renderer));
}


////////////////////////////////////////////////////////////
RendererBackend::RendererBackend(SDL_Renderer* renderer) :
m_renderer(renderer)
{
}


////////////////////////////////////////////////////////////
RendererBackend::~RendererBackend()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }
}


////////////////////////////////////////////////////////////
void RendererBackend::clear(Color color)
{
    if (!m_renderer)
        return;

    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(m_renderer);
}


////////////////////////////////////////////////////////////
void RendererBackend::present()
{
    if (!m_renderer)
        return;

    SDL_RenderPresent(m_renderer);
}


////////////////////////////////////////////////////////////
void RendererBackend::setViewport(const SDL_Rect* viewport)
{
    if (!m_renderer)
        return;

    SDL_SetRenderViewport(m_renderer, viewport);
}


////////////////////////////////////////////////////////////
void RendererBackend::setClipRect(const SDL_Rect* clipRect)
{
    if (!m_renderer)
        return;

    SDL_SetRenderClipRect(m_renderer, clipRect);
}


////////////////////////////////////////////////////////////
void RendererBackend::setBlendMode(const BlendMode& mode)
{
    if (!m_renderer)
        return;

    SDL_BlendMode sdlMode = convertBlendMode(mode);
    SDL_SetRenderDrawBlendMode(m_renderer, sdlMode);
}


////////////////////////////////////////////////////////////
void RendererBackend::drawPrimitives(const Vertex*  vertices,
                                      std::size_t    vertexCount,
                                      PrimitiveType  type,
                                      SDL_Texture*   texture)
{
    if (!m_renderer || vertexCount == 0)
        return;

    // Convert SFML vertices to SDL vertices
    convertVertices(vertices, vertexCount);

    // Generate indices based on primitive type
    generateIndices(type, vertexCount);

    if (m_indices.empty())
        return;

    // Draw geometry
    SDL_RenderGeometry(m_renderer,
                       texture,
                       m_sdlVertices.data(),
                       static_cast<int>(m_sdlVertices.size()),
                       m_indices.data(),
                       static_cast<int>(m_indices.size()));
}


////////////////////////////////////////////////////////////
void RendererBackend::drawTexture(SDL_Texture* texture, const SDL_FRect* srcRect, const SDL_FRect* dstRect)
{
    if (!m_renderer || !texture)
        return;

    SDL_RenderTexture(m_renderer, texture, srcRect, dstRect);
}


////////////////////////////////////////////////////////////
SDL_BlendMode RendererBackend::convertBlendMode(const BlendMode& mode)
{
    // Map SFML blend modes to SDL blend modes
    // This is a simplified mapping; full support would require custom blend modes

    // Check for common blend mode patterns
    using Factor   = BlendMode::Factor;
    using Equation = BlendMode::Equation;

    // Alpha blending: src * SrcAlpha + dst * OneMinusSrcAlpha
    if (mode.colorSrcFactor == Factor::SrcAlpha && mode.colorDstFactor == Factor::OneMinusSrcAlpha &&
        mode.colorEquation == Equation::Add && mode.alphaSrcFactor == Factor::One &&
        mode.alphaDstFactor == Factor::OneMinusSrcAlpha && mode.alphaEquation == Equation::Add)
    {
        return SDL_BLENDMODE_BLEND;
    }

    // Additive blending: src * SrcAlpha + dst * One
    if (mode.colorSrcFactor == Factor::SrcAlpha && mode.colorDstFactor == Factor::One &&
        mode.colorEquation == Equation::Add)
    {
        return SDL_BLENDMODE_ADD;
    }

    // Multiply blending: src * DstColor + dst * Zero
    if (mode.colorSrcFactor == Factor::DstColor && mode.colorDstFactor == Factor::Zero &&
        mode.colorEquation == Equation::Add)
    {
        return SDL_BLENDMODE_MUL;
    }

    // No blending: src * One + dst * Zero
    if (mode.colorSrcFactor == Factor::One && mode.colorDstFactor == Factor::Zero &&
        mode.colorEquation == Equation::Add)
    {
        return SDL_BLENDMODE_NONE;
    }

    // Default to alpha blending
    static bool warned = false;
    if (!warned)
    {
        err() << "Unsupported blend mode, falling back to SDL_BLENDMODE_BLEND" << std::endl;
        warned = true;
    }
    return SDL_BLENDMODE_BLEND;
}


////////////////////////////////////////////////////////////
void RendererBackend::convertVertices(const Vertex* vertices, std::size_t vertexCount)
{
    m_sdlVertices.resize(vertexCount);

    for (std::size_t i = 0; i < vertexCount; ++i)
    {
        const Vertex& sfVertex = vertices[i];
        SDL_Vertex&   sdlVertex = m_sdlVertices[i];

        // Position
        sdlVertex.position.x = sfVertex.position.x;
        sdlVertex.position.y = sfVertex.position.y;

        // Texture coordinates
        sdlVertex.tex_coord.x = sfVertex.texCoords.x;
        sdlVertex.tex_coord.y = sfVertex.texCoords.y;

        // Color
        sdlVertex.color.r = static_cast<float>(sfVertex.color.r) / 255.0f;
        sdlVertex.color.g = static_cast<float>(sfVertex.color.g) / 255.0f;
        sdlVertex.color.b = static_cast<float>(sfVertex.color.b) / 255.0f;
        sdlVertex.color.a = static_cast<float>(sfVertex.color.a) / 255.0f;
    }
}


////////////////////////////////////////////////////////////
void RendererBackend::generateIndices(PrimitiveType type, std::size_t vertexCount)
{
    m_indices.clear();

    switch (type)
    {
        case PrimitiveType::Points:
            // SDL_RenderGeometry doesn't support points, would need SDL_RenderPoints
            err() << "PrimitiveType::Points not supported with SDL_Renderer" << std::endl;
            break;

        case PrimitiveType::Lines:
            // SDL_RenderGeometry doesn't support lines, would need SDL_RenderLines
            err() << "PrimitiveType::Lines not supported with SDL_Renderer" << std::endl;
            break;

        case PrimitiveType::LineStrip:
            // Not directly supported
            err() << "PrimitiveType::LineStrip not supported with SDL_Renderer" << std::endl;
            break;

        case PrimitiveType::Triangles:
            // Direct mapping: each 3 vertices form a triangle
            m_indices.reserve(vertexCount);
            for (std::size_t i = 0; i < vertexCount; ++i)
                m_indices.push_back(static_cast<int>(i));
            break;

        case PrimitiveType::TriangleStrip:
        {
            // Convert triangle strip to triangle list
            if (vertexCount >= 3)
            {
                m_indices.reserve((vertexCount - 2) * 3);
                for (std::size_t i = 0; i < vertexCount - 2; ++i)
                {
                    if (i % 2 == 0)
                    {
                        // Even triangle: i, i+1, i+2
                        m_indices.push_back(static_cast<int>(i));
                        m_indices.push_back(static_cast<int>(i + 1));
                        m_indices.push_back(static_cast<int>(i + 2));
                    }
                    else
                    {
                        // Odd triangle: i, i+2, i+1 (reversed winding)
                        m_indices.push_back(static_cast<int>(i));
                        m_indices.push_back(static_cast<int>(i + 2));
                        m_indices.push_back(static_cast<int>(i + 1));
                    }
                }
            }
            break;
        }

        case PrimitiveType::TriangleFan:
        {
            // Convert triangle fan to triangle list
            if (vertexCount >= 3)
            {
                m_indices.reserve((vertexCount - 2) * 3);
                for (std::size_t i = 1; i < vertexCount - 1; ++i)
                {
                    m_indices.push_back(0);                          // Center vertex
                    m_indices.push_back(static_cast<int>(i));       // Current vertex
                    m_indices.push_back(static_cast<int>(i + 1));   // Next vertex
                }
            }
            break;
        }
    }
}

} // namespace sf::priv
