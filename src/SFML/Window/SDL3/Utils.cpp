#include <SFML/Window/SDL3/Utils.hpp>

namespace sf::priv
{
////////////////////////////////////////////////////////////
Keyboard::Key sdlKeyToSfml(SDL_Keycode key)
{
    // clang-format off
    switch (key)
    {
        case SDLK_A:            return Keyboard::Key::A;
        case SDLK_B:            return Keyboard::Key::B;
        case SDLK_C:            return Keyboard::Key::C;
        case SDLK_D:            return Keyboard::Key::D;
        case SDLK_E:            return Keyboard::Key::E;
        case SDLK_F:            return Keyboard::Key::F;
        case SDLK_G:            return Keyboard::Key::G;
        case SDLK_H:            return Keyboard::Key::H;
        case SDLK_I:            return Keyboard::Key::I;
        case SDLK_J:            return Keyboard::Key::J;
        case SDLK_K:            return Keyboard::Key::K;
        case SDLK_L:            return Keyboard::Key::L;
        case SDLK_M:            return Keyboard::Key::M;
        case SDLK_N:            return Keyboard::Key::N;
        case SDLK_O:            return Keyboard::Key::O;
        case SDLK_P:            return Keyboard::Key::P;
        case SDLK_Q:            return Keyboard::Key::Q;
        case SDLK_R:            return Keyboard::Key::R;
        case SDLK_S:            return Keyboard::Key::S;
        case SDLK_T:            return Keyboard::Key::T;
        case SDLK_U:            return Keyboard::Key::U;
        case SDLK_V:            return Keyboard::Key::V;
        case SDLK_W:            return Keyboard::Key::W;
        case SDLK_X:            return Keyboard::Key::X;
        case SDLK_Y:            return Keyboard::Key::Y;
        case SDLK_Z:            return Keyboard::Key::Z;
        case SDLK_0:            return Keyboard::Key::Num0;
        case SDLK_1:            return Keyboard::Key::Num1;
        case SDLK_2:            return Keyboard::Key::Num2;
        case SDLK_3:            return Keyboard::Key::Num3;
        case SDLK_4:            return Keyboard::Key::Num4;
        case SDLK_5:            return Keyboard::Key::Num5;
        case SDLK_6:            return Keyboard::Key::Num6;
        case SDLK_7:            return Keyboard::Key::Num7;
        case SDLK_8:            return Keyboard::Key::Num8;
        case SDLK_9:            return Keyboard::Key::Num9;
        case SDLK_ESCAPE:       return Keyboard::Key::Escape;
        case SDLK_LCTRL:        return Keyboard::Key::LControl;
        case SDLK_LSHIFT:       return Keyboard::Key::LShift;
        case SDLK_LALT:         return Keyboard::Key::LAlt;
        case SDLK_LGUI:         return Keyboard::Key::LSystem;
        case SDLK_RCTRL:        return Keyboard::Key::RControl;
        case SDLK_RSHIFT:       return Keyboard::Key::RShift;
        case SDLK_RALT:         return Keyboard::Key::RAlt;
        case SDLK_RGUI:         return Keyboard::Key::RSystem;
        case SDLK_MENU:         return Keyboard::Key::Menu;
        case SDLK_LEFTBRACKET:  return Keyboard::Key::LBracket;
        case SDLK_RIGHTBRACKET: return Keyboard::Key::RBracket;
        case SDLK_SEMICOLON:    return Keyboard::Key::Semicolon;
        case SDLK_COMMA:        return Keyboard::Key::Comma;
        case SDLK_PERIOD:       return Keyboard::Key::Period;
        case SDLK_APOSTROPHE:   return Keyboard::Key::Apostrophe;
        case SDLK_SLASH:        return Keyboard::Key::Slash;
        case SDLK_BACKSLASH:    return Keyboard::Key::Backslash;
        case SDLK_GRAVE:        return Keyboard::Key::Grave;
        case SDLK_EQUALS:       return Keyboard::Key::Equal;
        case SDLK_MINUS:        return Keyboard::Key::Hyphen;
        case SDLK_SPACE:        return Keyboard::Key::Space;
        case SDLK_RETURN:       return Keyboard::Key::Enter;
        case SDLK_BACKSPACE:    return Keyboard::Key::Backspace;
        case SDLK_TAB:          return Keyboard::Key::Tab;
        case SDLK_PAGEUP:       return Keyboard::Key::PageUp;
        case SDLK_PAGEDOWN:     return Keyboard::Key::PageDown;
        case SDLK_END:          return Keyboard::Key::End;
        case SDLK_HOME:         return Keyboard::Key::Home;
        case SDLK_INSERT:       return Keyboard::Key::Insert;
        case SDLK_DELETE:       return Keyboard::Key::Delete;
        case SDLK_KP_PLUS:      return Keyboard::Key::Add;
        case SDLK_KP_MINUS:     return Keyboard::Key::Subtract;
        case SDLK_KP_MULTIPLY:  return Keyboard::Key::Multiply;
        case SDLK_KP_DIVIDE:    return Keyboard::Key::Divide;
        case SDLK_LEFT:         return Keyboard::Key::Left;
        case SDLK_RIGHT:        return Keyboard::Key::Right;
        case SDLK_UP:           return Keyboard::Key::Up;
        case SDLK_DOWN:         return Keyboard::Key::Down;
        case SDLK_KP_0:         return Keyboard::Key::Numpad0;
        case SDLK_KP_1:         return Keyboard::Key::Numpad1;
        case SDLK_KP_2:         return Keyboard::Key::Numpad2;
        case SDLK_KP_3:         return Keyboard::Key::Numpad3;
        case SDLK_KP_4:         return Keyboard::Key::Numpad4;
        case SDLK_KP_5:         return Keyboard::Key::Numpad5;
        case SDLK_KP_6:         return Keyboard::Key::Numpad6;
        case SDLK_KP_7:         return Keyboard::Key::Numpad7;
        case SDLK_KP_8:         return Keyboard::Key::Numpad8;
        case SDLK_KP_9:         return Keyboard::Key::Numpad9;
        case SDLK_F1:           return Keyboard::Key::F1;
        case SDLK_F2:           return Keyboard::Key::F2;
        case SDLK_F3:           return Keyboard::Key::F3;
        case SDLK_F4:           return Keyboard::Key::F4;
        case SDLK_F5:           return Keyboard::Key::F5;
        case SDLK_F6:           return Keyboard::Key::F6;
        case SDLK_F7:           return Keyboard::Key::F7;
        case SDLK_F8:           return Keyboard::Key::F8;
        case SDLK_F9:           return Keyboard::Key::F9;
        case SDLK_F10:          return Keyboard::Key::F10;
        case SDLK_F11:          return Keyboard::Key::F11;
        case SDLK_F12:          return Keyboard::Key::F12;
        case SDLK_F13:          return Keyboard::Key::F13;
        case SDLK_F14:          return Keyboard::Key::F14;
        case SDLK_F15:          return Keyboard::Key::F15;
        case SDLK_PAUSE:        return Keyboard::Key::Pause;
        default:                return Keyboard::Key::Unknown;
    }
    // clang-format on
}


////////////////////////////////////////////////////////////
SDL_Keycode sfmlKeyToSdl(Keyboard::Key key)
{
    // clang-format off
    switch (key)
    {
        case Keyboard::Key::A:          return SDLK_A;
        case Keyboard::Key::B:          return SDLK_B;
        case Keyboard::Key::C:          return SDLK_C;
        case Keyboard::Key::D:          return SDLK_D;
        case Keyboard::Key::E:          return SDLK_E;
        case Keyboard::Key::F:          return SDLK_F;
        case Keyboard::Key::G:          return SDLK_G;
        case Keyboard::Key::H:          return SDLK_H;
        case Keyboard::Key::I:          return SDLK_I;
        case Keyboard::Key::J:          return SDLK_J;
        case Keyboard::Key::K:          return SDLK_K;
        case Keyboard::Key::L:          return SDLK_L;
        case Keyboard::Key::M:          return SDLK_M;
        case Keyboard::Key::N:          return SDLK_N;
        case Keyboard::Key::O:          return SDLK_O;
        case Keyboard::Key::P:          return SDLK_P;
        case Keyboard::Key::Q:          return SDLK_Q;
        case Keyboard::Key::R:          return SDLK_R;
        case Keyboard::Key::S:          return SDLK_S;
        case Keyboard::Key::T:          return SDLK_T;
        case Keyboard::Key::U:          return SDLK_U;
        case Keyboard::Key::V:          return SDLK_V;
        case Keyboard::Key::W:          return SDLK_W;
        case Keyboard::Key::X:          return SDLK_X;
        case Keyboard::Key::Y:          return SDLK_Y;
        case Keyboard::Key::Z:          return SDLK_Z;
        case Keyboard::Key::Num0:       return SDLK_0;
        case Keyboard::Key::Num1:       return SDLK_1;
        case Keyboard::Key::Num2:       return SDLK_2;
        case Keyboard::Key::Num3:       return SDLK_3;
        case Keyboard::Key::Num4:       return SDLK_4;
        case Keyboard::Key::Num5:       return SDLK_5;
        case Keyboard::Key::Num6:       return SDLK_6;
        case Keyboard::Key::Num7:       return SDLK_7;
        case Keyboard::Key::Num8:       return SDLK_8;
        case Keyboard::Key::Num9:       return SDLK_9;
        case Keyboard::Key::Escape:     return SDLK_ESCAPE;
        case Keyboard::Key::LControl:   return SDLK_LCTRL;
        case Keyboard::Key::LShift:     return SDLK_LSHIFT;
        case Keyboard::Key::LAlt:       return SDLK_LALT;
        case Keyboard::Key::LSystem:    return SDLK_LGUI;
        case Keyboard::Key::RControl:   return SDLK_RCTRL;
        case Keyboard::Key::RShift:     return SDLK_RSHIFT;
        case Keyboard::Key::RAlt:       return SDLK_RALT;
        case Keyboard::Key::RSystem:    return SDLK_RGUI;
        case Keyboard::Key::Menu:       return SDLK_MENU;
        case Keyboard::Key::LBracket:   return SDLK_LEFTBRACKET;
        case Keyboard::Key::RBracket:   return SDLK_RIGHTBRACKET;
        case Keyboard::Key::Semicolon:  return SDLK_SEMICOLON;
        case Keyboard::Key::Comma:      return SDLK_COMMA;
        case Keyboard::Key::Period:     return SDLK_PERIOD;
        case Keyboard::Key::Apostrophe: return SDLK_APOSTROPHE;
        case Keyboard::Key::Slash:      return SDLK_SLASH;
        case Keyboard::Key::Backslash:  return SDLK_BACKSLASH;
        case Keyboard::Key::Grave:      return SDLK_GRAVE;
        case Keyboard::Key::Equal:      return SDLK_EQUALS;
        case Keyboard::Key::Hyphen:     return SDLK_MINUS;
        case Keyboard::Key::Space:      return SDLK_SPACE;
        case Keyboard::Key::Enter:      return SDLK_RETURN;
        case Keyboard::Key::Backspace:  return SDLK_BACKSPACE;
        case Keyboard::Key::Tab:        return SDLK_TAB;
        case Keyboard::Key::PageUp:     return SDLK_PAGEUP;
        case Keyboard::Key::PageDown:   return SDLK_PAGEDOWN;
        case Keyboard::Key::End:        return SDLK_END;
        case Keyboard::Key::Home:       return SDLK_HOME;
        case Keyboard::Key::Insert:     return SDLK_INSERT;
        case Keyboard::Key::Delete:     return SDLK_DELETE;
        case Keyboard::Key::Add:        return SDLK_KP_PLUS;
        case Keyboard::Key::Subtract:   return SDLK_KP_MINUS;
        case Keyboard::Key::Multiply:   return SDLK_KP_MULTIPLY;
        case Keyboard::Key::Divide:     return SDLK_KP_DIVIDE;
        case Keyboard::Key::Left:       return SDLK_LEFT;
        case Keyboard::Key::Right:      return SDLK_RIGHT;
        case Keyboard::Key::Up:         return SDLK_UP;
        case Keyboard::Key::Down:       return SDLK_DOWN;
        case Keyboard::Key::Numpad0:    return SDLK_KP_0;
        case Keyboard::Key::Numpad1:    return SDLK_KP_1;
        case Keyboard::Key::Numpad2:    return SDLK_KP_2;
        case Keyboard::Key::Numpad3:    return SDLK_KP_3;
        case Keyboard::Key::Numpad4:    return SDLK_KP_4;
        case Keyboard::Key::Numpad5:    return SDLK_KP_5;
        case Keyboard::Key::Numpad6:    return SDLK_KP_6;
        case Keyboard::Key::Numpad7:    return SDLK_KP_7;
        case Keyboard::Key::Numpad8:    return SDLK_KP_8;
        case Keyboard::Key::Numpad9:    return SDLK_KP_9;
        case Keyboard::Key::F1:         return SDLK_F1;
        case Keyboard::Key::F2:         return SDLK_F2;
        case Keyboard::Key::F3:         return SDLK_F3;
        case Keyboard::Key::F4:         return SDLK_F4;
        case Keyboard::Key::F5:         return SDLK_F5;
        case Keyboard::Key::F6:         return SDLK_F6;
        case Keyboard::Key::F7:         return SDLK_F7;
        case Keyboard::Key::F8:         return SDLK_F8;
        case Keyboard::Key::F9:         return SDLK_F9;
        case Keyboard::Key::F10:        return SDLK_F10;
        case Keyboard::Key::F11:        return SDLK_F11;
        case Keyboard::Key::F12:        return SDLK_F12;
        case Keyboard::Key::F13:        return SDLK_F13;
        case Keyboard::Key::F14:        return SDLK_F14;
        case Keyboard::Key::F15:        return SDLK_F15;
        case Keyboard::Key::Pause:      return SDLK_PAUSE;
        default:                        return SDLK_UNKNOWN;
    }
    // clang-format on
}


////////////////////////////////////////////////////////////
Keyboard::Scancode sdlScancodeToSfml(SDL_Scancode code)
{
    if (code >= SDL_SCANCODE_A && code <= SDL_SCANCODE_Z)
        return static_cast<Keyboard::Scancode>(static_cast<int>(Keyboard::Scancode::A) + (code - SDL_SCANCODE_A));

    if (code >= SDL_SCANCODE_1 && code <= SDL_SCANCODE_9)
        return static_cast<Keyboard::Scancode>(static_cast<int>(Keyboard::Scancode::Num1) + (code - SDL_SCANCODE_1));

    if (code == SDL_SCANCODE_0)
        return Keyboard::Scancode::Num0;

    // clang-format off
    switch (code)
    {
        case SDL_SCANCODE_ESCAPE:       return Keyboard::Scancode::Escape;
        case SDL_SCANCODE_LCTRL:        return Keyboard::Scancode::LControl;
        case SDL_SCANCODE_LSHIFT:       return Keyboard::Scancode::LShift;
        case SDL_SCANCODE_LALT:         return Keyboard::Scancode::LAlt;
        case SDL_SCANCODE_LGUI:         return Keyboard::Scancode::LSystem;
        case SDL_SCANCODE_RCTRL:        return Keyboard::Scancode::RControl;
        case SDL_SCANCODE_RSHIFT:       return Keyboard::Scancode::RShift;
        case SDL_SCANCODE_RALT:         return Keyboard::Scancode::RAlt;
        case SDL_SCANCODE_RGUI:         return Keyboard::Scancode::RSystem;
        case SDL_SCANCODE_MENU:         return Keyboard::Scancode::Menu;
        case SDL_SCANCODE_LEFTBRACKET:  return Keyboard::Scancode::LBracket;
        case SDL_SCANCODE_RIGHTBRACKET: return Keyboard::Scancode::RBracket;
        case SDL_SCANCODE_SEMICOLON:    return Keyboard::Scancode::Semicolon;
        case SDL_SCANCODE_COMMA:        return Keyboard::Scancode::Comma;
        case SDL_SCANCODE_PERIOD:       return Keyboard::Scancode::Period;
        case SDL_SCANCODE_APOSTROPHE:   return Keyboard::Scancode::Apostrophe;
        case SDL_SCANCODE_SLASH:        return Keyboard::Scancode::Slash;
        case SDL_SCANCODE_BACKSLASH:    return Keyboard::Scancode::Backslash;
        case SDL_SCANCODE_GRAVE:        return Keyboard::Scancode::Grave;
        case SDL_SCANCODE_EQUALS:       return Keyboard::Scancode::Equal;
        case SDL_SCANCODE_MINUS:        return Keyboard::Scancode::Hyphen;
        case SDL_SCANCODE_SPACE:        return Keyboard::Scancode::Space;
        case SDL_SCANCODE_RETURN:       return Keyboard::Scancode::Enter;
        case SDL_SCANCODE_BACKSPACE:    return Keyboard::Scancode::Backspace;
        case SDL_SCANCODE_TAB:          return Keyboard::Scancode::Tab;
        case SDL_SCANCODE_PAGEUP:       return Keyboard::Scancode::PageUp;
        case SDL_SCANCODE_PAGEDOWN:     return Keyboard::Scancode::PageDown;
        case SDL_SCANCODE_END:          return Keyboard::Scancode::End;
        case SDL_SCANCODE_HOME:         return Keyboard::Scancode::Home;
        case SDL_SCANCODE_INSERT:       return Keyboard::Scancode::Insert;
        case SDL_SCANCODE_DELETE:       return Keyboard::Scancode::Delete;
        case SDL_SCANCODE_KP_PLUS:      return Keyboard::Scancode::NumpadPlus;
        case SDL_SCANCODE_KP_MINUS:     return Keyboard::Scancode::NumpadMinus;
        case SDL_SCANCODE_KP_MULTIPLY:  return Keyboard::Scancode::NumpadMultiply;
        case SDL_SCANCODE_KP_DIVIDE:    return Keyboard::Scancode::NumpadDivide;
        case SDL_SCANCODE_LEFT:         return Keyboard::Scancode::Left;
        case SDL_SCANCODE_RIGHT:        return Keyboard::Scancode::Right;
        case SDL_SCANCODE_UP:           return Keyboard::Scancode::Up;
        case SDL_SCANCODE_DOWN:         return Keyboard::Scancode::Down;
        case SDL_SCANCODE_KP_0:         return Keyboard::Scancode::Numpad0;
        case SDL_SCANCODE_KP_1:         return Keyboard::Scancode::Numpad1;
        case SDL_SCANCODE_KP_2:         return Keyboard::Scancode::Numpad2;
        case SDL_SCANCODE_KP_3:         return Keyboard::Scancode::Numpad3;
        case SDL_SCANCODE_KP_4:         return Keyboard::Scancode::Numpad4;
        case SDL_SCANCODE_KP_5:         return Keyboard::Scancode::Numpad5;
        case SDL_SCANCODE_KP_6:         return Keyboard::Scancode::Numpad6;
        case SDL_SCANCODE_KP_7:         return Keyboard::Scancode::Numpad7;
        case SDL_SCANCODE_KP_8:         return Keyboard::Scancode::Numpad8;
        case SDL_SCANCODE_KP_9:         return Keyboard::Scancode::Numpad9;
        case SDL_SCANCODE_F1:           return Keyboard::Scancode::F1;
        case SDL_SCANCODE_F2:           return Keyboard::Scancode::F2;
        case SDL_SCANCODE_F3:           return Keyboard::Scancode::F3;
        case SDL_SCANCODE_F4:           return Keyboard::Scancode::F4;
        case SDL_SCANCODE_F5:           return Keyboard::Scancode::F5;
        case SDL_SCANCODE_F6:           return Keyboard::Scancode::F6;
        case SDL_SCANCODE_F7:           return Keyboard::Scancode::F7;
        case SDL_SCANCODE_F8:           return Keyboard::Scancode::F8;
        case SDL_SCANCODE_F9:           return Keyboard::Scancode::F9;
        case SDL_SCANCODE_F10:          return Keyboard::Scancode::F10;
        case SDL_SCANCODE_F11:          return Keyboard::Scancode::F11;
        case SDL_SCANCODE_F12:          return Keyboard::Scancode::F12;
        case SDL_SCANCODE_F13:          return Keyboard::Scancode::F13;
        case SDL_SCANCODE_F14:          return Keyboard::Scancode::F14;
        case SDL_SCANCODE_F15:          return Keyboard::Scancode::F15;
        case SDL_SCANCODE_PAUSE:        return Keyboard::Scancode::Pause;
        default:                        return Keyboard::Scancode::Unknown;
    }
    // clang-format on
}


////////////////////////////////////////////////////////////
SDL_Scancode sfmlScancodeToSdl(Keyboard::Scancode code)
{
    if (code >= Keyboard::Scancode::A && code <= Keyboard::Scancode::Z)
        return static_cast<SDL_Scancode>(
            SDL_SCANCODE_A + (static_cast<int>(code) - static_cast<int>(Keyboard::Scancode::A)));

    if (code >= Keyboard::Scancode::Num1 && code <= Keyboard::Scancode::Num9)
        return static_cast<SDL_Scancode>(
            SDL_SCANCODE_1 + (static_cast<int>(code) - static_cast<int>(Keyboard::Scancode::Num1)));

    if (code == Keyboard::Scancode::Num0)
        return SDL_SCANCODE_0;

    // clang-format off
    switch (code)
    {
        case Keyboard::Scancode::Escape:     return SDL_SCANCODE_ESCAPE;
        case Keyboard::Scancode::LControl:   return SDL_SCANCODE_LCTRL;
        case Keyboard::Scancode::LShift:     return SDL_SCANCODE_LSHIFT;
        case Keyboard::Scancode::LAlt:       return SDL_SCANCODE_LALT;
        case Keyboard::Scancode::LSystem:    return SDL_SCANCODE_LGUI;
        case Keyboard::Scancode::RControl:   return SDL_SCANCODE_RCTRL;
        case Keyboard::Scancode::RShift:     return SDL_SCANCODE_RSHIFT;
        case Keyboard::Scancode::RAlt:       return SDL_SCANCODE_RALT;
        case Keyboard::Scancode::RSystem:    return SDL_SCANCODE_RGUI;
        case Keyboard::Scancode::Menu:       return SDL_SCANCODE_MENU;
        case Keyboard::Scancode::LBracket:   return SDL_SCANCODE_LEFTBRACKET;
        case Keyboard::Scancode::RBracket:   return SDL_SCANCODE_RIGHTBRACKET;
        case Keyboard::Scancode::Semicolon:  return SDL_SCANCODE_SEMICOLON;
        case Keyboard::Scancode::Comma:      return SDL_SCANCODE_COMMA;
        case Keyboard::Scancode::Period:     return SDL_SCANCODE_PERIOD;
        case Keyboard::Scancode::Apostrophe: return SDL_SCANCODE_APOSTROPHE;
        case Keyboard::Scancode::Slash:      return SDL_SCANCODE_SLASH;
        case Keyboard::Scancode::Backslash:  return SDL_SCANCODE_BACKSLASH;
        case Keyboard::Scancode::Grave:      return SDL_SCANCODE_GRAVE;
        case Keyboard::Scancode::Equal:      return SDL_SCANCODE_EQUALS;
        case Keyboard::Scancode::Hyphen:     return SDL_SCANCODE_MINUS;
        case Keyboard::Scancode::Space:      return SDL_SCANCODE_SPACE;
        case Keyboard::Scancode::Enter:      return SDL_SCANCODE_RETURN;
        case Keyboard::Scancode::Backspace:  return SDL_SCANCODE_BACKSPACE;
        case Keyboard::Scancode::Tab:        return SDL_SCANCODE_TAB;
        case Keyboard::Scancode::PageUp:     return SDL_SCANCODE_PAGEUP;
        case Keyboard::Scancode::PageDown:   return SDL_SCANCODE_PAGEDOWN;
        case Keyboard::Scancode::End:        return SDL_SCANCODE_END;
        case Keyboard::Scancode::Home:       return SDL_SCANCODE_HOME;
        case Keyboard::Scancode::Insert:     return SDL_SCANCODE_INSERT;
        case Keyboard::Scancode::Delete:     return SDL_SCANCODE_DELETE;
        case Keyboard::Scancode::NumpadPlus:     return SDL_SCANCODE_KP_PLUS;
        case Keyboard::Scancode::NumpadMinus:    return SDL_SCANCODE_KP_MINUS;
        case Keyboard::Scancode::NumpadMultiply: return SDL_SCANCODE_KP_MULTIPLY;
        case Keyboard::Scancode::NumpadDivide:   return SDL_SCANCODE_KP_DIVIDE;
        case Keyboard::Scancode::Left:       return SDL_SCANCODE_LEFT;
        case Keyboard::Scancode::Right:      return SDL_SCANCODE_RIGHT;
        case Keyboard::Scancode::Up:         return SDL_SCANCODE_UP;
        case Keyboard::Scancode::Down:       return SDL_SCANCODE_DOWN;
        case Keyboard::Scancode::Numpad0:    return SDL_SCANCODE_KP_0;
        case Keyboard::Scancode::Numpad1:    return SDL_SCANCODE_KP_1;
        case Keyboard::Scancode::Numpad2:    return SDL_SCANCODE_KP_2;
        case Keyboard::Scancode::Numpad3:    return SDL_SCANCODE_KP_3;
        case Keyboard::Scancode::Numpad4:    return SDL_SCANCODE_KP_4;
        case Keyboard::Scancode::Numpad5:    return SDL_SCANCODE_KP_5;
        case Keyboard::Scancode::Numpad6:    return SDL_SCANCODE_KP_6;
        case Keyboard::Scancode::Numpad7:    return SDL_SCANCODE_KP_7;
        case Keyboard::Scancode::Numpad8:    return SDL_SCANCODE_KP_8;
        case Keyboard::Scancode::Numpad9:    return SDL_SCANCODE_KP_9;
        case Keyboard::Scancode::F1:         return SDL_SCANCODE_F1;
        case Keyboard::Scancode::F2:         return SDL_SCANCODE_F2;
        case Keyboard::Scancode::F3:         return SDL_SCANCODE_F3;
        case Keyboard::Scancode::F4:         return SDL_SCANCODE_F4;
        case Keyboard::Scancode::F5:         return SDL_SCANCODE_F5;
        case Keyboard::Scancode::F6:         return SDL_SCANCODE_F6;
        case Keyboard::Scancode::F7:         return SDL_SCANCODE_F7;
        case Keyboard::Scancode::F8:         return SDL_SCANCODE_F8;
        case Keyboard::Scancode::F9:         return SDL_SCANCODE_F9;
        case Keyboard::Scancode::F10:        return SDL_SCANCODE_F10;
        case Keyboard::Scancode::F11:        return SDL_SCANCODE_F11;
        case Keyboard::Scancode::F12:        return SDL_SCANCODE_F12;
        case Keyboard::Scancode::F13:        return SDL_SCANCODE_F13;
        case Keyboard::Scancode::F14:        return SDL_SCANCODE_F14;
        case Keyboard::Scancode::F15:        return SDL_SCANCODE_F15;
        case Keyboard::Scancode::Pause:      return SDL_SCANCODE_PAUSE;
        default:                        return SDL_SCANCODE_UNKNOWN;
    }
    // clang-format on
}


////////////////////////////////////////////////////////////
Mouse::Button sdlMouseButtonToSfml(Uint8 button)
{
    // clang-format off
    switch (button)
    {
        case SDL_BUTTON_LEFT:   return Mouse::Button::Left;
        case SDL_BUTTON_RIGHT:  return Mouse::Button::Right;
        case SDL_BUTTON_MIDDLE: return Mouse::Button::Middle;
        case SDL_BUTTON_X1:     return Mouse::Button::Extra1;
        case SDL_BUTTON_X2:     return Mouse::Button::Extra2;
        default:                return Mouse::Button::Left;
    }
    // clang-format on
}


////////////////////////////////////////////////////////////
void ensureSdlVideoInit()
{
    if (!SDL_WasInit(SDL_INIT_VIDEO))
    {
        SDL_Init(SDL_INIT_VIDEO);
    }
}

} // namespace sf::priv
