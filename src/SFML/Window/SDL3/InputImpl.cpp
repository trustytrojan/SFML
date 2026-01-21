#include <SFML/Window/InputImpl.hpp>
#include <SFML/Window/WindowBase.hpp>

#include <SDL3/SDL.h>

namespace sf::priv::InputImpl
{
bool isKeyPressed(Keyboard::Key)
{
    return false;
}
bool isKeyPressed(Keyboard::Scancode)
{
    return false;
}
Keyboard::Key localize(Keyboard::Scancode)
{
    return Keyboard::Key::Unknown;
}
Keyboard::Scancode delocalize(Keyboard::Key)
{
    return Keyboard::Scancode::Unknown;
}
String getDescription(Keyboard::Scancode)
{
    return "";
}
void setVirtualKeyboardVisible(bool visible)
{
    if (visible)
        SDL_StartTextInput(nullptr);
    else
        SDL_StopTextInput(nullptr);
}
bool isMouseButtonPressed(Mouse::Button button)
{
    uint32_t state = SDL_GetMouseState(nullptr, nullptr);
    switch (button)
    {
        case Mouse::Button::Left:
            return (state & SDL_BUTTON_LMASK) != 0;
        case Mouse::Button::Right:
            return (state & SDL_BUTTON_RMASK) != 0;
        case Mouse::Button::Middle:
            return (state & SDL_BUTTON_MMASK) != 0;
        case Mouse::Button::Extra1:
            return (state & SDL_BUTTON_X1MASK) != 0;
        case Mouse::Button::Extra2:
            return (state & SDL_BUTTON_X2MASK) != 0;
        default:
            return false;
    }
}
Vector2i getMousePosition()
{
    float x = 0;
    float y = 0;
    SDL_GetGlobalMouseState(&x, &y);
    return {static_cast<int>(x), static_cast<int>(y)};
}
Vector2i getMousePosition(const WindowBase&)
{
    float x = 0;
    float y = 0;
    SDL_GetMouseState(&x, &y);
    return {static_cast<int>(x), static_cast<int>(y)};
}
void setMousePosition(Vector2i)
{
    // SDL_WarpMouseGlobal(position.x, position.y);
}
void setMousePosition(Vector2i, const WindowBase&)
{
    // SDL_WarpMouseInWindow(..., position.x, position.y);
}
bool isTouchDown(unsigned int)
{
    return false;
}
Vector2i getTouchPosition(unsigned int)
{
    return {};
}
Vector2i getTouchPosition(unsigned int, const WindowBase&)
{
    return {};
}
} // namespace sf::priv::InputImpl
