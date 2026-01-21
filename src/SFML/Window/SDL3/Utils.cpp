#include <SFML/Window/SDL3/Utils.hpp>

namespace sf::priv
{
////////////////////////////////////////////////////////////
#define SFML_KEY_MAP(sdl, sfml) case sdl: return Keyboard::Key::sfml
#define SFML_KEYCODE_MAP(sfml, sdl) case Keyboard::Key::sfml: return sdl
#define SFML_SCAN_MAP(sdl, sfml) case sdl: return Keyboard::Scancode::sfml
#define SFML_SCANCODE_MAP(sfml, sdl) case Keyboard::Scancode::sfml: return sdl

////////////////////////////////////////////////////////////
Keyboard::Key sdlKeyToSfml(SDL_Keycode key)
{
    // clang-format off
    switch (key)
    {
        SFML_KEY_MAP(SDLK_A, A);
        SFML_KEY_MAP(SDLK_B, B);
        SFML_KEY_MAP(SDLK_C, C);
        SFML_KEY_MAP(SDLK_D, D);
        SFML_KEY_MAP(SDLK_E, E);
        SFML_KEY_MAP(SDLK_F, F);
        SFML_KEY_MAP(SDLK_G, G);
        SFML_KEY_MAP(SDLK_H, H);
        SFML_KEY_MAP(SDLK_I, I);
        SFML_KEY_MAP(SDLK_J, J);
        SFML_KEY_MAP(SDLK_K, K);
        SFML_KEY_MAP(SDLK_L, L);
        SFML_KEY_MAP(SDLK_M, M);
        SFML_KEY_MAP(SDLK_N, N);
        SFML_KEY_MAP(SDLK_O, O);
        SFML_KEY_MAP(SDLK_P, P);
        SFML_KEY_MAP(SDLK_Q, Q);
        SFML_KEY_MAP(SDLK_R, R);
        SFML_KEY_MAP(SDLK_S, S);
        SFML_KEY_MAP(SDLK_T, T);
        SFML_KEY_MAP(SDLK_U, U);
        SFML_KEY_MAP(SDLK_V, V);
        SFML_KEY_MAP(SDLK_W, W);
        SFML_KEY_MAP(SDLK_X, X);
        SFML_KEY_MAP(SDLK_Y, Y);
        SFML_KEY_MAP(SDLK_Z, Z);
        SFML_KEY_MAP(SDLK_0, Num0);
        SFML_KEY_MAP(SDLK_1, Num1);
        SFML_KEY_MAP(SDLK_2, Num2);
        SFML_KEY_MAP(SDLK_3, Num3);
        SFML_KEY_MAP(SDLK_4, Num4);
        SFML_KEY_MAP(SDLK_5, Num5);
        SFML_KEY_MAP(SDLK_6, Num6);
        SFML_KEY_MAP(SDLK_7, Num7);
        SFML_KEY_MAP(SDLK_8, Num8);
        SFML_KEY_MAP(SDLK_9, Num9);
        SFML_KEY_MAP(SDLK_ESCAPE, Escape);
        SFML_KEY_MAP(SDLK_LCTRL, LControl);
        SFML_KEY_MAP(SDLK_LSHIFT, LShift);
        SFML_KEY_MAP(SDLK_LALT, LAlt);
        SFML_KEY_MAP(SDLK_LGUI, LSystem);
        SFML_KEY_MAP(SDLK_RCTRL, RControl);
        SFML_KEY_MAP(SDLK_RSHIFT, RShift);
        SFML_KEY_MAP(SDLK_RALT, RAlt);
        SFML_KEY_MAP(SDLK_RGUI, RSystem);
        SFML_KEY_MAP(SDLK_MENU, Menu);
        SFML_KEY_MAP(SDLK_LEFTBRACKET, LBracket);
        SFML_KEY_MAP(SDLK_RIGHTBRACKET, RBracket);
        SFML_KEY_MAP(SDLK_SEMICOLON, Semicolon);
        SFML_KEY_MAP(SDLK_COMMA, Comma);
        SFML_KEY_MAP(SDLK_PERIOD, Period);
        SFML_KEY_MAP(SDLK_APOSTROPHE, Apostrophe);
        SFML_KEY_MAP(SDLK_SLASH, Slash);
        SFML_KEY_MAP(SDLK_BACKSLASH, Backslash);
        SFML_KEY_MAP(SDLK_GRAVE, Grave);
        SFML_KEY_MAP(SDLK_EQUALS, Equal);
        SFML_KEY_MAP(SDLK_MINUS, Hyphen);
        SFML_KEY_MAP(SDLK_SPACE, Space);
        SFML_KEY_MAP(SDLK_RETURN, Enter);
        SFML_KEY_MAP(SDLK_BACKSPACE, Backspace);
        SFML_KEY_MAP(SDLK_TAB, Tab);
        SFML_KEY_MAP(SDLK_PAGEUP, PageUp);
        SFML_KEY_MAP(SDLK_PAGEDOWN, PageDown);
        SFML_KEY_MAP(SDLK_END, End);
        SFML_KEY_MAP(SDLK_HOME, Home);
        SFML_KEY_MAP(SDLK_INSERT, Insert);
        SFML_KEY_MAP(SDLK_DELETE, Delete);
        SFML_KEY_MAP(SDLK_KP_PLUS, Add);
        SFML_KEY_MAP(SDLK_KP_MINUS, Subtract);
        SFML_KEY_MAP(SDLK_KP_MULTIPLY, Multiply);
        SFML_KEY_MAP(SDLK_KP_DIVIDE, Divide);
        SFML_KEY_MAP(SDLK_LEFT, Left);
        SFML_KEY_MAP(SDLK_RIGHT, Right);
        SFML_KEY_MAP(SDLK_UP, Up);
        SFML_KEY_MAP(SDLK_DOWN, Down);
        SFML_KEY_MAP(SDLK_KP_0, Numpad0);
        SFML_KEY_MAP(SDLK_KP_1, Numpad1);
        SFML_KEY_MAP(SDLK_KP_2, Numpad2);
        SFML_KEY_MAP(SDLK_KP_3, Numpad3);
        SFML_KEY_MAP(SDLK_KP_4, Numpad4);
        SFML_KEY_MAP(SDLK_KP_5, Numpad5);
        SFML_KEY_MAP(SDLK_KP_6, Numpad6);
        SFML_KEY_MAP(SDLK_KP_7, Numpad7);
        SFML_KEY_MAP(SDLK_KP_8, Numpad8);
        SFML_KEY_MAP(SDLK_KP_9, Numpad9);
        SFML_KEY_MAP(SDLK_F1, F1);
        SFML_KEY_MAP(SDLK_F2, F2);
        SFML_KEY_MAP(SDLK_F3, F3);
        SFML_KEY_MAP(SDLK_F4, F4);
        SFML_KEY_MAP(SDLK_F5, F5);
        SFML_KEY_MAP(SDLK_F6, F6);
        SFML_KEY_MAP(SDLK_F7, F7);
        SFML_KEY_MAP(SDLK_F8, F8);
        SFML_KEY_MAP(SDLK_F9, F9);
        SFML_KEY_MAP(SDLK_F10, F10);
        SFML_KEY_MAP(SDLK_F11, F11);
        SFML_KEY_MAP(SDLK_F12, F12);
        SFML_KEY_MAP(SDLK_F13, F13);
        SFML_KEY_MAP(SDLK_F14, F14);
        SFML_KEY_MAP(SDLK_F15, F15);
        SFML_KEY_MAP(SDLK_PAUSE, Pause);
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
        SFML_KEYCODE_MAP(A, SDLK_A);
        SFML_KEYCODE_MAP(B, SDLK_B);
        SFML_KEYCODE_MAP(C, SDLK_C);
        SFML_KEYCODE_MAP(D, SDLK_D);
        SFML_KEYCODE_MAP(E, SDLK_E);
        SFML_KEYCODE_MAP(F, SDLK_F);
        SFML_KEYCODE_MAP(G, SDLK_G);
        SFML_KEYCODE_MAP(H, SDLK_H);
        SFML_KEYCODE_MAP(I, SDLK_I);
        SFML_KEYCODE_MAP(J, SDLK_J);
        SFML_KEYCODE_MAP(K, SDLK_K);
        SFML_KEYCODE_MAP(L, SDLK_L);
        SFML_KEYCODE_MAP(M, SDLK_M);
        SFML_KEYCODE_MAP(N, SDLK_N);
        SFML_KEYCODE_MAP(O, SDLK_O);
        SFML_KEYCODE_MAP(P, SDLK_P);
        SFML_KEYCODE_MAP(Q, SDLK_Q);
        SFML_KEYCODE_MAP(R, SDLK_R);
        SFML_KEYCODE_MAP(S, SDLK_S);
        SFML_KEYCODE_MAP(T, SDLK_T);
        SFML_KEYCODE_MAP(U, SDLK_U);
        SFML_KEYCODE_MAP(V, SDLK_V);
        SFML_KEYCODE_MAP(W, SDLK_W);
        SFML_KEYCODE_MAP(X, SDLK_X);
        SFML_KEYCODE_MAP(Y, SDLK_Y);
        SFML_KEYCODE_MAP(Z, SDLK_Z);
        SFML_KEYCODE_MAP(Num0, SDLK_0);
        SFML_KEYCODE_MAP(Num1, SDLK_1);
        SFML_KEYCODE_MAP(Num2, SDLK_2);
        SFML_KEYCODE_MAP(Num3, SDLK_3);
        SFML_KEYCODE_MAP(Num4, SDLK_4);
        SFML_KEYCODE_MAP(Num5, SDLK_5);
        SFML_KEYCODE_MAP(Num6, SDLK_6);
        SFML_KEYCODE_MAP(Num7, SDLK_7);
        SFML_KEYCODE_MAP(Num8, SDLK_8);
        SFML_KEYCODE_MAP(Num9, SDLK_9);
        SFML_KEYCODE_MAP(Escape, SDLK_ESCAPE);
        SFML_KEYCODE_MAP(LControl, SDLK_LCTRL);
        SFML_KEYCODE_MAP(LShift, SDLK_LSHIFT);
        SFML_KEYCODE_MAP(LAlt, SDLK_LALT);
        SFML_KEYCODE_MAP(LSystem, SDLK_LGUI);
        SFML_KEYCODE_MAP(RControl, SDLK_RCTRL);
        SFML_KEYCODE_MAP(RShift, SDLK_RSHIFT);
        SFML_KEYCODE_MAP(RAlt, SDLK_RALT);
        SFML_KEYCODE_MAP(RSystem, SDLK_RGUI);
        SFML_KEYCODE_MAP(Menu, SDLK_MENU);
        SFML_KEYCODE_MAP(LBracket, SDLK_LEFTBRACKET);
        SFML_KEYCODE_MAP(RBracket, SDLK_RIGHTBRACKET);
        SFML_KEYCODE_MAP(Semicolon, SDLK_SEMICOLON);
        SFML_KEYCODE_MAP(Comma, SDLK_COMMA);
        SFML_KEYCODE_MAP(Period, SDLK_PERIOD);
        SFML_KEYCODE_MAP(Apostrophe, SDLK_APOSTROPHE);
        SFML_KEYCODE_MAP(Slash, SDLK_SLASH);
        SFML_KEYCODE_MAP(Backslash, SDLK_BACKSLASH);
        SFML_KEYCODE_MAP(Grave, SDLK_GRAVE);
        SFML_KEYCODE_MAP(Equal, SDLK_EQUALS);
        SFML_KEYCODE_MAP(Hyphen, SDLK_MINUS);
        SFML_KEYCODE_MAP(Space, SDLK_SPACE);
        SFML_KEYCODE_MAP(Enter, SDLK_RETURN);
        SFML_KEYCODE_MAP(Backspace, SDLK_BACKSPACE);
        SFML_KEYCODE_MAP(Tab, SDLK_TAB);
        SFML_KEYCODE_MAP(PageUp, SDLK_PAGEUP);
        SFML_KEYCODE_MAP(PageDown, SDLK_PAGEDOWN);
        SFML_KEYCODE_MAP(End, SDLK_END);
        SFML_KEYCODE_MAP(Home, SDLK_HOME);
        SFML_KEYCODE_MAP(Insert, SDLK_INSERT);
        SFML_KEYCODE_MAP(Delete, SDLK_DELETE);
        SFML_KEYCODE_MAP(Add, SDLK_KP_PLUS);
        SFML_KEYCODE_MAP(Subtract, SDLK_KP_MINUS);
        SFML_KEYCODE_MAP(Multiply, SDLK_KP_MULTIPLY);
        SFML_KEYCODE_MAP(Divide, SDLK_KP_DIVIDE);
        SFML_KEYCODE_MAP(Left, SDLK_LEFT);
        SFML_KEYCODE_MAP(Right, SDLK_RIGHT);
        SFML_KEYCODE_MAP(Up, SDLK_UP);
        SFML_KEYCODE_MAP(Down, SDLK_DOWN);
        SFML_KEYCODE_MAP(Numpad0, SDLK_KP_0);
        SFML_KEYCODE_MAP(Numpad1, SDLK_KP_1);
        SFML_KEYCODE_MAP(Numpad2, SDLK_KP_2);
        SFML_KEYCODE_MAP(Numpad3, SDLK_KP_3);
        SFML_KEYCODE_MAP(Numpad4, SDLK_KP_4);
        SFML_KEYCODE_MAP(Numpad5, SDLK_KP_5);
        SFML_KEYCODE_MAP(Numpad6, SDLK_KP_6);
        SFML_KEYCODE_MAP(Numpad7, SDLK_KP_7);
        SFML_KEYCODE_MAP(Numpad8, SDLK_KP_8);
        SFML_KEYCODE_MAP(Numpad9, SDLK_KP_9);
        SFML_KEYCODE_MAP(F1, SDLK_F1);
        SFML_KEYCODE_MAP(F2, SDLK_F2);
        SFML_KEYCODE_MAP(F3, SDLK_F3);
        SFML_KEYCODE_MAP(F4, SDLK_F4);
        SFML_KEYCODE_MAP(F5, SDLK_F5);
        SFML_KEYCODE_MAP(F6, SDLK_F6);
        SFML_KEYCODE_MAP(F7, SDLK_F7);
        SFML_KEYCODE_MAP(F8, SDLK_F8);
        SFML_KEYCODE_MAP(F9, SDLK_F9);
        SFML_KEYCODE_MAP(F10, SDLK_F10);
        SFML_KEYCODE_MAP(F11, SDLK_F11);
        SFML_KEYCODE_MAP(F12, SDLK_F12);
        SFML_KEYCODE_MAP(F13, SDLK_F13);
        SFML_KEYCODE_MAP(F14, SDLK_F14);
        SFML_KEYCODE_MAP(F15, SDLK_F15);
        SFML_KEYCODE_MAP(Pause, SDLK_PAUSE);
        default:                return SDLK_UNKNOWN;
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
        SFML_SCAN_MAP(SDL_SCANCODE_ESCAPE, Escape);
        SFML_SCAN_MAP(SDL_SCANCODE_LCTRL, LControl);
        SFML_SCAN_MAP(SDL_SCANCODE_LSHIFT, LShift);
        SFML_SCAN_MAP(SDL_SCANCODE_LALT, LAlt);
        SFML_SCAN_MAP(SDL_SCANCODE_LGUI, LSystem);
        SFML_SCAN_MAP(SDL_SCANCODE_RCTRL, RControl);
        SFML_SCAN_MAP(SDL_SCANCODE_RSHIFT, RShift);
        SFML_SCAN_MAP(SDL_SCANCODE_RALT, RAlt);
        SFML_SCAN_MAP(SDL_SCANCODE_RGUI, RSystem);
        SFML_SCAN_MAP(SDL_SCANCODE_MENU, Menu);
        SFML_SCAN_MAP(SDL_SCANCODE_LEFTBRACKET, LBracket);
        SFML_SCAN_MAP(SDL_SCANCODE_RIGHTBRACKET, RBracket);
        SFML_SCAN_MAP(SDL_SCANCODE_SEMICOLON, Semicolon);
        SFML_SCAN_MAP(SDL_SCANCODE_COMMA, Comma);
        SFML_SCAN_MAP(SDL_SCANCODE_PERIOD, Period);
        SFML_SCAN_MAP(SDL_SCANCODE_APOSTROPHE, Apostrophe);
        SFML_SCAN_MAP(SDL_SCANCODE_SLASH, Slash);
        SFML_SCAN_MAP(SDL_SCANCODE_BACKSLASH, Backslash);
        SFML_SCAN_MAP(SDL_SCANCODE_GRAVE, Grave);
        SFML_SCAN_MAP(SDL_SCANCODE_EQUALS, Equal);
        SFML_SCAN_MAP(SDL_SCANCODE_MINUS, Hyphen);
        SFML_SCAN_MAP(SDL_SCANCODE_SPACE, Space);
        SFML_SCAN_MAP(SDL_SCANCODE_RETURN, Enter);
        SFML_SCAN_MAP(SDL_SCANCODE_BACKSPACE, Backspace);
        SFML_SCAN_MAP(SDL_SCANCODE_TAB, Tab);
        SFML_SCAN_MAP(SDL_SCANCODE_PAGEUP, PageUp);
        SFML_SCAN_MAP(SDL_SCANCODE_PAGEDOWN, PageDown);
        SFML_SCAN_MAP(SDL_SCANCODE_END, End);
        SFML_SCAN_MAP(SDL_SCANCODE_HOME, Home);
        SFML_SCAN_MAP(SDL_SCANCODE_INSERT, Insert);
        SFML_SCAN_MAP(SDL_SCANCODE_DELETE, Delete);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_PLUS, NumpadPlus);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_MINUS, NumpadMinus);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_MULTIPLY, NumpadMultiply);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_DIVIDE, NumpadDivide);
        SFML_SCAN_MAP(SDL_SCANCODE_LEFT, Left);
        SFML_SCAN_MAP(SDL_SCANCODE_RIGHT, Right);
        SFML_SCAN_MAP(SDL_SCANCODE_UP, Up);
        SFML_SCAN_MAP(SDL_SCANCODE_DOWN, Down);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_0, Numpad0);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_1, Numpad1);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_2, Numpad2);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_3, Numpad3);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_4, Numpad4);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_5, Numpad5);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_6, Numpad6);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_7, Numpad7);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_8, Numpad8);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_9, Numpad9);
        SFML_SCAN_MAP(SDL_SCANCODE_F1, F1);
        SFML_SCAN_MAP(SDL_SCANCODE_F2, F2);
        SFML_SCAN_MAP(SDL_SCANCODE_F3, F3);
        SFML_SCAN_MAP(SDL_SCANCODE_F4, F4);
        SFML_SCAN_MAP(SDL_SCANCODE_F5, F5);
        SFML_SCAN_MAP(SDL_SCANCODE_F6, F6);
        SFML_SCAN_MAP(SDL_SCANCODE_F7, F7);
        SFML_SCAN_MAP(SDL_SCANCODE_F8, F8);
        SFML_SCAN_MAP(SDL_SCANCODE_F9, F9);
        SFML_SCAN_MAP(SDL_SCANCODE_F10, F10);
        SFML_SCAN_MAP(SDL_SCANCODE_F11, F11);
        SFML_SCAN_MAP(SDL_SCANCODE_F12, F12);
        SFML_SCAN_MAP(SDL_SCANCODE_F13, F13);
        SFML_SCAN_MAP(SDL_SCANCODE_F14, F14);
        SFML_SCAN_MAP(SDL_SCANCODE_F15, F15);
        SFML_SCAN_MAP(SDL_SCANCODE_F16, F16);
        SFML_SCAN_MAP(SDL_SCANCODE_F17, F17);
        SFML_SCAN_MAP(SDL_SCANCODE_F18, F18);
        SFML_SCAN_MAP(SDL_SCANCODE_F19, F19);
        SFML_SCAN_MAP(SDL_SCANCODE_F20, F20);
        SFML_SCAN_MAP(SDL_SCANCODE_F21, F21);
        SFML_SCAN_MAP(SDL_SCANCODE_F22, F22);
        SFML_SCAN_MAP(SDL_SCANCODE_F23, F23);
        SFML_SCAN_MAP(SDL_SCANCODE_F24, F24);
        SFML_SCAN_MAP(SDL_SCANCODE_CAPSLOCK, CapsLock);
        SFML_SCAN_MAP(SDL_SCANCODE_PRINTSCREEN, PrintScreen);
        SFML_SCAN_MAP(SDL_SCANCODE_SCROLLLOCK, ScrollLock);
        SFML_SCAN_MAP(SDL_SCANCODE_PAUSE, Pause);
        SFML_SCAN_MAP(SDL_SCANCODE_NUMLOCKCLEAR, NumLock);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_EQUALS, NumpadEqual);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_ENTER, NumpadEnter);
        SFML_SCAN_MAP(SDL_SCANCODE_KP_PERIOD, NumpadDecimal);
        SFML_SCAN_MAP(SDL_SCANCODE_NONUSBACKSLASH, NonUsBackslash);
        SFML_SCAN_MAP(SDL_SCANCODE_APPLICATION, Application);
        SFML_SCAN_MAP(SDL_SCANCODE_EXECUTE, Execute);
        SFML_SCAN_MAP(SDL_SCANCODE_MODE, ModeChange);
        SFML_SCAN_MAP(SDL_SCANCODE_HELP, Help);
        SFML_SCAN_MAP(SDL_SCANCODE_SELECT, Select);
        SFML_SCAN_MAP(SDL_SCANCODE_AGAIN, Redo);
        SFML_SCAN_MAP(SDL_SCANCODE_UNDO, Undo);
        SFML_SCAN_MAP(SDL_SCANCODE_CUT, Cut);
        SFML_SCAN_MAP(SDL_SCANCODE_COPY, Copy);
        SFML_SCAN_MAP(SDL_SCANCODE_PASTE, Paste);
        SFML_SCAN_MAP(SDL_SCANCODE_MUTE, VolumeMute);
        SFML_SCAN_MAP(SDL_SCANCODE_VOLUMEUP, VolumeUp);
        SFML_SCAN_MAP(SDL_SCANCODE_VOLUMEDOWN, VolumeDown);
        SFML_SCAN_MAP(SDL_SCANCODE_MEDIA_PLAY_PAUSE, MediaPlayPause);
        SFML_SCAN_MAP(SDL_SCANCODE_MEDIA_STOP, MediaStop);
        SFML_SCAN_MAP(SDL_SCANCODE_MEDIA_NEXT_TRACK, MediaNextTrack);
        SFML_SCAN_MAP(SDL_SCANCODE_MEDIA_PREVIOUS_TRACK, MediaPreviousTrack);
        SFML_SCAN_MAP(SDL_SCANCODE_AC_BACK, Back);
        SFML_SCAN_MAP(SDL_SCANCODE_AC_FORWARD, Forward);
        SFML_SCAN_MAP(SDL_SCANCODE_AC_REFRESH, Refresh);
        SFML_SCAN_MAP(SDL_SCANCODE_AC_STOP, Stop);
        SFML_SCAN_MAP(SDL_SCANCODE_AC_SEARCH, Search);
        SFML_SCAN_MAP(SDL_SCANCODE_AC_BOOKMARKS, Favorites);
        SFML_SCAN_MAP(SDL_SCANCODE_AC_HOME, HomePage);
        SFML_SCAN_MAP(SDL_SCANCODE_MEDIA_SELECT, LaunchMediaSelect);
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
        SFML_SCANCODE_MAP(Escape, SDL_SCANCODE_ESCAPE);
        SFML_SCANCODE_MAP(LControl, SDL_SCANCODE_LCTRL);
        SFML_SCANCODE_MAP(LShift, SDL_SCANCODE_LSHIFT);
        SFML_SCANCODE_MAP(LAlt, SDL_SCANCODE_LALT);
        SFML_SCANCODE_MAP(LSystem, SDL_SCANCODE_LGUI);
        SFML_SCANCODE_MAP(RControl, SDL_SCANCODE_RCTRL);
        SFML_SCANCODE_MAP(RShift, SDL_SCANCODE_RSHIFT);
        SFML_SCANCODE_MAP(RAlt, SDL_SCANCODE_RALT);
        SFML_SCANCODE_MAP(RSystem, SDL_SCANCODE_RGUI);
        SFML_SCANCODE_MAP(Menu, SDL_SCANCODE_MENU);
        SFML_SCANCODE_MAP(LBracket, SDL_SCANCODE_LEFTBRACKET);
        SFML_SCANCODE_MAP(RBracket, SDL_SCANCODE_RIGHTBRACKET);
        SFML_SCANCODE_MAP(Semicolon, SDL_SCANCODE_SEMICOLON);
        SFML_SCANCODE_MAP(Comma, SDL_SCANCODE_COMMA);
        SFML_SCANCODE_MAP(Period, SDL_SCANCODE_PERIOD);
        SFML_SCANCODE_MAP(Apostrophe, SDL_SCANCODE_APOSTROPHE);
        SFML_SCANCODE_MAP(Slash, SDL_SCANCODE_SLASH);
        SFML_SCANCODE_MAP(Backslash, SDL_SCANCODE_BACKSLASH);
        SFML_SCANCODE_MAP(Grave, SDL_SCANCODE_GRAVE);
        SFML_SCANCODE_MAP(Equal, SDL_SCANCODE_EQUALS);
        SFML_SCANCODE_MAP(Hyphen, SDL_SCANCODE_MINUS);
        SFML_SCANCODE_MAP(Space, SDL_SCANCODE_SPACE);
        SFML_SCANCODE_MAP(Enter, SDL_SCANCODE_RETURN);
        SFML_SCANCODE_MAP(Backspace, SDL_SCANCODE_BACKSPACE);
        SFML_SCANCODE_MAP(Tab, SDL_SCANCODE_TAB);
        SFML_SCANCODE_MAP(PageUp, SDL_SCANCODE_PAGEUP);
        SFML_SCANCODE_MAP(PageDown, SDL_SCANCODE_PAGEDOWN);
        SFML_SCANCODE_MAP(End, SDL_SCANCODE_END);
        SFML_SCANCODE_MAP(Home, SDL_SCANCODE_HOME);
        SFML_SCANCODE_MAP(Insert, SDL_SCANCODE_INSERT);
        SFML_SCANCODE_MAP(Delete, SDL_SCANCODE_DELETE);
        SFML_SCANCODE_MAP(NumpadPlus, SDL_SCANCODE_KP_PLUS);
        SFML_SCANCODE_MAP(NumpadMinus, SDL_SCANCODE_KP_MINUS);
        SFML_SCANCODE_MAP(NumpadMultiply, SDL_SCANCODE_KP_MULTIPLY);
        SFML_SCANCODE_MAP(NumpadDivide, SDL_SCANCODE_KP_DIVIDE);
        SFML_SCANCODE_MAP(Left, SDL_SCANCODE_LEFT);
        SFML_SCANCODE_MAP(Right, SDL_SCANCODE_RIGHT);
        SFML_SCANCODE_MAP(Up, SDL_SCANCODE_UP);
        SFML_SCANCODE_MAP(Down, SDL_SCANCODE_DOWN);
        SFML_SCANCODE_MAP(Numpad0, SDL_SCANCODE_KP_0);
        SFML_SCANCODE_MAP(Numpad1, SDL_SCANCODE_KP_1);
        SFML_SCANCODE_MAP(Numpad2, SDL_SCANCODE_KP_2);
        SFML_SCANCODE_MAP(Numpad3, SDL_SCANCODE_KP_3);
        SFML_SCANCODE_MAP(Numpad4, SDL_SCANCODE_KP_4);
        SFML_SCANCODE_MAP(Numpad5, SDL_SCANCODE_KP_5);
        SFML_SCANCODE_MAP(Numpad6, SDL_SCANCODE_KP_6);
        SFML_SCANCODE_MAP(Numpad7, SDL_SCANCODE_KP_7);
        SFML_SCANCODE_MAP(Numpad8, SDL_SCANCODE_KP_8);
        SFML_SCANCODE_MAP(Numpad9, SDL_SCANCODE_KP_9);
        SFML_SCANCODE_MAP(F1, SDL_SCANCODE_F1);
        SFML_SCANCODE_MAP(F2, SDL_SCANCODE_F2);
        SFML_SCANCODE_MAP(F3, SDL_SCANCODE_F3);
        SFML_SCANCODE_MAP(F4, SDL_SCANCODE_F4);
        SFML_SCANCODE_MAP(F5, SDL_SCANCODE_F5);
        SFML_SCANCODE_MAP(F6, SDL_SCANCODE_F6);
        SFML_SCANCODE_MAP(F7, SDL_SCANCODE_F7);
        SFML_SCANCODE_MAP(F8, SDL_SCANCODE_F8);
        SFML_SCANCODE_MAP(F9, SDL_SCANCODE_F9);
        SFML_SCANCODE_MAP(F10, SDL_SCANCODE_F10);
        SFML_SCANCODE_MAP(F11, SDL_SCANCODE_F11);
        SFML_SCANCODE_MAP(F12, SDL_SCANCODE_F12);
        SFML_SCANCODE_MAP(F13, SDL_SCANCODE_F13);
        SFML_SCANCODE_MAP(F14, SDL_SCANCODE_F14);
        SFML_SCANCODE_MAP(F15, SDL_SCANCODE_F15);
        SFML_SCANCODE_MAP(F16, SDL_SCANCODE_F16);
        SFML_SCANCODE_MAP(F17, SDL_SCANCODE_F17);
        SFML_SCANCODE_MAP(F18, SDL_SCANCODE_F18);
        SFML_SCANCODE_MAP(F19, SDL_SCANCODE_F19);
        SFML_SCANCODE_MAP(F20, SDL_SCANCODE_F20);
        SFML_SCANCODE_MAP(F21, SDL_SCANCODE_F21);
        SFML_SCANCODE_MAP(F22, SDL_SCANCODE_F22);
        SFML_SCANCODE_MAP(F23, SDL_SCANCODE_F23);
        SFML_SCANCODE_MAP(F24, SDL_SCANCODE_F24);
        SFML_SCANCODE_MAP(CapsLock, SDL_SCANCODE_CAPSLOCK);
        SFML_SCANCODE_MAP(PrintScreen, SDL_SCANCODE_PRINTSCREEN);
        SFML_SCANCODE_MAP(ScrollLock, SDL_SCANCODE_SCROLLLOCK);
        SFML_SCANCODE_MAP(Pause, SDL_SCANCODE_PAUSE);
        SFML_SCANCODE_MAP(NumLock, SDL_SCANCODE_NUMLOCKCLEAR);
        SFML_SCANCODE_MAP(NumpadEqual, SDL_SCANCODE_KP_EQUALS);
        SFML_SCANCODE_MAP(NumpadEnter, SDL_SCANCODE_KP_ENTER);
        SFML_SCANCODE_MAP(NumpadDecimal, SDL_SCANCODE_KP_PERIOD);
        SFML_SCANCODE_MAP(NonUsBackslash, SDL_SCANCODE_NONUSBACKSLASH);
        SFML_SCANCODE_MAP(Application, SDL_SCANCODE_APPLICATION);
        SFML_SCANCODE_MAP(Execute, SDL_SCANCODE_EXECUTE);
        SFML_SCANCODE_MAP(ModeChange, SDL_SCANCODE_MODE);
        SFML_SCANCODE_MAP(Help, SDL_SCANCODE_HELP);
        SFML_SCANCODE_MAP(Select, SDL_SCANCODE_SELECT);
        SFML_SCANCODE_MAP(Redo, SDL_SCANCODE_AGAIN);
        SFML_SCANCODE_MAP(Undo, SDL_SCANCODE_UNDO);
        SFML_SCANCODE_MAP(Cut, SDL_SCANCODE_CUT);
        SFML_SCANCODE_MAP(Copy, SDL_SCANCODE_COPY);
        SFML_SCANCODE_MAP(Paste, SDL_SCANCODE_PASTE);
        SFML_SCANCODE_MAP(VolumeMute, SDL_SCANCODE_MUTE);
        SFML_SCANCODE_MAP(VolumeUp, SDL_SCANCODE_VOLUMEUP);
        SFML_SCANCODE_MAP(VolumeDown, SDL_SCANCODE_VOLUMEDOWN);
        SFML_SCANCODE_MAP(MediaPlayPause, SDL_SCANCODE_MEDIA_PLAY_PAUSE);
        SFML_SCANCODE_MAP(MediaStop, SDL_SCANCODE_MEDIA_STOP);
        SFML_SCANCODE_MAP(MediaNextTrack, SDL_SCANCODE_MEDIA_NEXT_TRACK);
        SFML_SCANCODE_MAP(MediaPreviousTrack, SDL_SCANCODE_MEDIA_PREVIOUS_TRACK);
        SFML_SCANCODE_MAP(Back, SDL_SCANCODE_AC_BACK);
        SFML_SCANCODE_MAP(Forward, SDL_SCANCODE_AC_FORWARD);
        SFML_SCANCODE_MAP(Refresh, SDL_SCANCODE_AC_REFRESH);
        SFML_SCANCODE_MAP(Stop, SDL_SCANCODE_AC_STOP);
        SFML_SCANCODE_MAP(Search, SDL_SCANCODE_AC_SEARCH);
        SFML_SCANCODE_MAP(Favorites, SDL_SCANCODE_AC_BOOKMARKS);
        SFML_SCANCODE_MAP(HomePage, SDL_SCANCODE_AC_HOME);
        SFML_SCANCODE_MAP(LaunchMediaSelect, SDL_SCANCODE_MEDIA_SELECT);
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
