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
// clang-format off
#include <SDL3/SDL.h>
#include <SDL3/SDL_keycode.h>
// clang-format on
#include <SFML/Window/SDL3/WindowImplSdl3.hpp>

#include <SFML/System/Err.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Utf.hpp>

#include <ostream>


namespace
{
////////////////////////////////////////////////////////////
/// \brief Convert SDL3 keycode to SFML key code
////////////////////////////////////////////////////////////
sf::Keyboard::Key sdlKeyToSfml(SDL_Keycode key)
{
    switch (key)
    {
            // clang-format off
        case SDLK_A:            return sf::Keyboard::Key::A;
        case SDLK_B:            return sf::Keyboard::Key::B;
        case SDLK_C:            return sf::Keyboard::Key::C;
        case SDLK_D:            return sf::Keyboard::Key::D;
        case SDLK_E:            return sf::Keyboard::Key::E;
        case SDLK_F:            return sf::Keyboard::Key::F;
        case SDLK_G:            return sf::Keyboard::Key::G;
        case SDLK_H:            return sf::Keyboard::Key::H;
        case SDLK_I:            return sf::Keyboard::Key::I;
        case SDLK_J:            return sf::Keyboard::Key::J;
        case SDLK_K:            return sf::Keyboard::Key::K;
        case SDLK_L:            return sf::Keyboard::Key::L;
        case SDLK_M:            return sf::Keyboard::Key::M;
        case SDLK_N:            return sf::Keyboard::Key::N;
        case SDLK_O:            return sf::Keyboard::Key::O;
        case SDLK_P:            return sf::Keyboard::Key::P;
        case SDLK_Q:            return sf::Keyboard::Key::Q;
        case SDLK_R:            return sf::Keyboard::Key::R;
        case SDLK_S:            return sf::Keyboard::Key::S;
        case SDLK_T:            return sf::Keyboard::Key::T;
        case SDLK_U:            return sf::Keyboard::Key::U;
        case SDLK_V:            return sf::Keyboard::Key::V;
        case SDLK_W:            return sf::Keyboard::Key::W;
        case SDLK_X:            return sf::Keyboard::Key::X;
        case SDLK_Y:            return sf::Keyboard::Key::Y;
        case SDLK_Z:            return sf::Keyboard::Key::Z;
        case SDLK_0:            return sf::Keyboard::Key::Num0;
        case SDLK_1:            return sf::Keyboard::Key::Num1;
        case SDLK_2:            return sf::Keyboard::Key::Num2;
        case SDLK_3:            return sf::Keyboard::Key::Num3;
        case SDLK_4:            return sf::Keyboard::Key::Num4;
        case SDLK_5:            return sf::Keyboard::Key::Num5;
        case SDLK_6:            return sf::Keyboard::Key::Num6;
        case SDLK_7:            return sf::Keyboard::Key::Num7;
        case SDLK_8:            return sf::Keyboard::Key::Num8;
        case SDLK_9:            return sf::Keyboard::Key::Num9;
        case SDLK_ESCAPE:       return sf::Keyboard::Key::Escape;
        case SDLK_LCTRL:        return sf::Keyboard::Key::LControl;
        case SDLK_LSHIFT:       return sf::Keyboard::Key::LShift;
        case SDLK_LALT:         return sf::Keyboard::Key::LAlt;
        case SDLK_LGUI:         return sf::Keyboard::Key::LSystem;
        case SDLK_RCTRL:        return sf::Keyboard::Key::RControl;
        case SDLK_RSHIFT:       return sf::Keyboard::Key::RShift;
        case SDLK_RALT:         return sf::Keyboard::Key::RAlt;
        case SDLK_RGUI:         return sf::Keyboard::Key::RSystem;
        case SDLK_MENU:         return sf::Keyboard::Key::Menu;
        case SDLK_LEFTBRACKET:  return sf::Keyboard::Key::LBracket;
        case SDLK_RIGHTBRACKET: return sf::Keyboard::Key::RBracket;
        case SDLK_SEMICOLON:    return sf::Keyboard::Key::Semicolon;
        case SDLK_COMMA:        return sf::Keyboard::Key::Comma;
        case SDLK_PERIOD:       return sf::Keyboard::Key::Period;
        case SDLK_APOSTROPHE:   return sf::Keyboard::Key::Apostrophe;
        case SDLK_SLASH:        return sf::Keyboard::Key::Slash;
        case SDLK_BACKSLASH:    return sf::Keyboard::Key::Backslash;
        case SDLK_GRAVE:        return sf::Keyboard::Key::Grave;
        case SDLK_EQUALS:       return sf::Keyboard::Key::Equal;
        case SDLK_MINUS:        return sf::Keyboard::Key::Hyphen;
        case SDLK_SPACE:        return sf::Keyboard::Key::Space;
        case SDLK_RETURN:       return sf::Keyboard::Key::Enter;
        case SDLK_BACKSPACE:    return sf::Keyboard::Key::Backspace;
        case SDLK_TAB:          return sf::Keyboard::Key::Tab;
        case SDLK_PAGEUP:       return sf::Keyboard::Key::PageUp;
        case SDLK_PAGEDOWN:     return sf::Keyboard::Key::PageDown;
        case SDLK_END:          return sf::Keyboard::Key::End;
        case SDLK_HOME:         return sf::Keyboard::Key::Home;
        case SDLK_INSERT:       return sf::Keyboard::Key::Insert;
        case SDLK_DELETE:       return sf::Keyboard::Key::Delete;
        case SDLK_KP_PLUS:      return sf::Keyboard::Key::Add;
        case SDLK_KP_MINUS:     return sf::Keyboard::Key::Subtract;
        case SDLK_KP_MULTIPLY:  return sf::Keyboard::Key::Multiply;
        case SDLK_KP_DIVIDE:    return sf::Keyboard::Key::Divide;
        case SDLK_LEFT:         return sf::Keyboard::Key::Left;
        case SDLK_RIGHT:        return sf::Keyboard::Key::Right;
        case SDLK_UP:           return sf::Keyboard::Key::Up;
        case SDLK_DOWN:         return sf::Keyboard::Key::Down;
        case SDLK_KP_0:         return sf::Keyboard::Key::Numpad0;
        case SDLK_KP_1:         return sf::Keyboard::Key::Numpad1;
        case SDLK_KP_2:         return sf::Keyboard::Key::Numpad2;
        case SDLK_KP_3:         return sf::Keyboard::Key::Numpad3;
        case SDLK_KP_4:         return sf::Keyboard::Key::Numpad4;
        case SDLK_KP_5:         return sf::Keyboard::Key::Numpad5;
        case SDLK_KP_6:         return sf::Keyboard::Key::Numpad6;
        case SDLK_KP_7:         return sf::Keyboard::Key::Numpad7;
        case SDLK_KP_8:         return sf::Keyboard::Key::Numpad8;
        case SDLK_KP_9:         return sf::Keyboard::Key::Numpad9;
        case SDLK_F1:           return sf::Keyboard::Key::F1;
        case SDLK_F2:           return sf::Keyboard::Key::F2;
        case SDLK_F3:           return sf::Keyboard::Key::F3;
        case SDLK_F4:           return sf::Keyboard::Key::F4;
        case SDLK_F5:           return sf::Keyboard::Key::F5;
        case SDLK_F6:           return sf::Keyboard::Key::F6;
        case SDLK_F7:           return sf::Keyboard::Key::F7;
        case SDLK_F8:           return sf::Keyboard::Key::F8;
        case SDLK_F9:           return sf::Keyboard::Key::F9;
        case SDLK_F10:          return sf::Keyboard::Key::F10;
        case SDLK_F11:          return sf::Keyboard::Key::F11;
        case SDLK_F12:          return sf::Keyboard::Key::F12;
        case SDLK_F13:          return sf::Keyboard::Key::F13;
        case SDLK_F14:          return sf::Keyboard::Key::F14;
        case SDLK_F15:          return sf::Keyboard::Key::F15;
        case SDLK_PAUSE:        return sf::Keyboard::Key::Pause;
        default:                return sf::Keyboard::Key::Unknown;
            // clang-format on
    }
}

////////////////////////////////////////////////////////////
/// \brief Convert SDL3 mouse button to SFML mouse button
////////////////////////////////////////////////////////////
sf::Mouse::Button sdlMouseButtonToSfml(Uint8 button)
{
    switch (button)
    {
            // clang-format off
        case SDL_BUTTON_LEFT:   return sf::Mouse::Button::Left;
        case SDL_BUTTON_RIGHT:  return sf::Mouse::Button::Right;
        case SDL_BUTTON_MIDDLE: return sf::Mouse::Button::Middle;
        case SDL_BUTTON_X1:     return sf::Mouse::Button::Extra1;
        case SDL_BUTTON_X2:     return sf::Mouse::Button::Extra2;
        default:                return sf::Mouse::Button::Left;
            // clang-format on
    }
}

} // anonymous namespace


namespace sf::priv
{
////////////////////////////////////////////////////////////
WindowImplSdl3::WindowImplSdl3(WindowHandle /*handle*/)
{
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
WindowImplSdl3::WindowImplSdl3(VideoMode mode, const String& title, std::uint32_t style, State state, const ContextSettings& /*settings*/)
{
    // Initialize SDL if not already initialized
    if (!SDL_WasInit(SDL_INIT_VIDEO))
    {
        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            err() << "Failed to initialize SDL3: " << SDL_GetError() << std::endl;
            return;
        }
    }

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
                                     {}, // scancode (SDL3 uses different scancodes)
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_ALT),
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_CTRL),
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_SHIFT),
                                     static_cast<bool>(sdlEvent.key.mod & SDL_KMOD_GUI)};
        }

        case SDL_EVENT_KEY_UP:
        {
            return Event::KeyReleased{sdlKeyToSfml(sdlEvent.key.key),
                                      {}, // scancode
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
