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
#include <SFML/Graphics/GLCheck.hpp>
#include <SFML/Graphics/GLExtensions.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderTextureImplFBO.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Window/VideoMode.hpp>

#ifdef SFML_USE_SDL_RENDERER
    #include <SFML/Graphics/SDL3/RendererBackend.hpp>
    #include <SDL3/SDL.h>
#endif


namespace sf
{
////////////////////////////////////////////////////////////
RenderWindow::RenderWindow(VideoMode mode, const String& title, std::uint32_t style, State state, const ContextSettings& settings)
{
    // Don't call the base class constructor because it contains virtual function calls
    Window::create(mode, title, style, state, settings);
}


////////////////////////////////////////////////////////////
RenderWindow::RenderWindow(VideoMode mode, const String& title, State state, const ContextSettings& settings)
{
    // Don't call the base class constructor because it contains virtual function calls
    Window::create(mode, title, sf::Style::Default, state, settings);
}


////////////////////////////////////////////////////////////
RenderWindow::RenderWindow(WindowHandle handle, const ContextSettings& settings)
{
    // Don't call the base class constructor because it contains virtual function calls
    Window::create(handle, settings);
}


////////////////////////////////////////////////////////////
Vector2u RenderWindow::getSize() const
{
    return Window::getSize();
}


////////////////////////////////////////////////////////////
void RenderWindow::setIcon(const Image& icon)
{
    setIcon(icon.getSize(), icon.getPixelsPtr());
}


////////////////////////////////////////////////////////////
bool RenderWindow::isSrgb() const
{
    return getSettings().sRgbCapable;
}


////////////////////////////////////////////////////////////
bool RenderWindow::setActive(bool active)
{
#ifdef SFML_USE_SDL_RENDERER
    // SDL_Renderer doesn't use the same context activation model
    // Just update RenderTarget tracking
    return RenderTarget::setActive(active);
#else
    bool result = Window::setActive(active);

    // Update RenderTarget tracking
    if (result)
        result = RenderTarget::setActive(active);

    // If FBOs are available, make sure none are bound when we
    // try to draw to the default framebuffer of the RenderWindow
    if (active && result && priv::RenderTextureImplFBO::isAvailable())
    {
        glCheck(GLEXT_glBindFramebuffer(GLEXT_GL_FRAMEBUFFER, m_defaultFrameBuffer));

        return true;
    }

    return result;
#endif
}


////////////////////////////////////////////////////////////
void RenderWindow::onCreate()
{
#ifdef SFML_USE_SDL_RENDERER
    // Create SDL_Renderer for this window
    SDL_Window* window = static_cast<SDL_Window*>(getNativeHandle());
    m_rendererBackend = priv::RendererBackend::create(window);
    
    if (!m_rendererBackend)
    {
        // Failed to create renderer, this is a fatal error
        return;
    }
    
    // Initialize the render target part
    RenderTarget::initialize();
#else
    if (priv::RenderTextureImplFBO::isAvailable())
    {
        // Retrieve the framebuffer ID we have to bind when targeting the window for rendering
        // We assume that this window's context is still active at this point
        glCheck(glGetIntegerv(GLEXT_GL_FRAMEBUFFER_BINDING, reinterpret_cast<GLint*>(&m_defaultFrameBuffer)));
    }

    // Just initialize the render target part
    RenderTarget::initialize();
#endif
}


////////////////////////////////////////////////////////////
void RenderWindow::onResize()
{
    // Update the current view (recompute the viewport, which is stored in relative coordinates)
    setView(getView());
}


#ifdef SFML_USE_SDL_RENDERER
////////////////////////////////////////////////////////////
void RenderWindow::clear(Color color)
{
    if (m_rendererBackend)
    {
        m_rendererBackend->clear(color);
    }
}


////////////////////////////////////////////////////////////  
void RenderWindow::display()
{
    if (m_rendererBackend)
    {
        m_rendererBackend->present();
    }
}
#endif

} // namespace sf
