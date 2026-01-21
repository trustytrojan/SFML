#include <SFML/Window/InputImpl.hpp>
#include <SFML/Window/SDL3/Utils.hpp>
#include <SFML/Window/WindowBase.hpp>

#include <SDL3/SDL.h>

#include <cstring>

namespace sf::priv::InputImpl
{
bool isKeyPressed(Keyboard::Key key)
{
    SDL_Keycode sdlKey = sfmlKeyToSdl(key);
    if (sdlKey == SDLK_UNKNOWN)
        return false;

    return SDL_GetKeyboardState(nullptr)[SDL_GetScancodeFromKey(sdlKey, nullptr)];
}
bool isKeyPressed(Keyboard::Scancode scancode)
{
    SDL_Scancode sdlScancode = sfmlScancodeToSdl(scancode);
    if (sdlScancode == SDL_SCANCODE_UNKNOWN)
        return false;

    return SDL_GetKeyboardState(nullptr)[sdlScancode];
}
Keyboard::Key localize(Keyboard::Scancode scancode)
{
    SDL_Scancode sdlScancode = sfmlScancodeToSdl(scancode);
    if (sdlScancode == SDL_SCANCODE_UNKNOWN)
        return Keyboard::Key::Unknown;

    return sdlKeyToSfml(SDL_GetKeyFromScancode(sdlScancode, SDL_KMOD_NONE, false));
}
Keyboard::Scancode delocalize(Keyboard::Key key)
{
    SDL_Keycode sdlKey = sfmlKeyToSdl(key);
    if (sdlKey == SDLK_UNKNOWN)
        return Keyboard::Scancode::Unknown;

    return sdlScancodeToSfml(SDL_GetScancodeFromKey(sdlKey, nullptr));
}
String getDescription(Keyboard::Scancode scancode)
{
    SDL_Scancode sdlScancode = sfmlScancodeToSdl(scancode);
    if (sdlScancode == SDL_SCANCODE_UNKNOWN)
        return "";

    const char* name = SDL_GetScancodeName(sdlScancode);
    if (name)
        return String::fromUtf8(name, name + std::strlen(name));

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
void setMousePosition(Vector2i position)
{
    SDL_WarpMouseGlobal(static_cast<float>(position.x), static_cast<float>(position.y));
}
void setMousePosition(Vector2i position, const WindowBase& relativeTo)
{
    SDL_WarpMouseInWindow(relativeTo.getNativeHandle(), static_cast<float>(position.x), static_cast<float>(position.y));
}
bool isTouchDown(unsigned int finger)
{
    int          count   = 0;
    SDL_TouchID* devices = SDL_GetTouchDevices(&count);
    bool         down    = false;
    if (devices && count > 0)
    {
        int          fingerCount = 0;
        SDL_Finger** fingers     = SDL_GetTouchFingers(devices[0], &fingerCount);
        if (fingers)
        {
            down = static_cast<int>(finger) < fingerCount;
            SDL_free(static_cast<void*>(fingers));
        }
    }
    SDL_free(devices);
    return down;
}

Vector2i getTouchPosition(unsigned int finger)
{
    int          count   = 0;
    SDL_TouchID* devices = SDL_GetTouchDevices(&count);
    Vector2i     position;
    if (devices && count > 0)
    {
        int          fingerCount = 0;
        SDL_Finger** fingers     = SDL_GetTouchFingers(devices[0], &fingerCount);
        if (fingers)
        {
            if (static_cast<int>(finger) < fingerCount)
            {
                int            displayCount = 0;
                SDL_DisplayID* displays     = SDL_GetDisplays(&displayCount);
                if (displays && displayCount > 0)
                {
                    SDL_Rect rect;
                    SDL_GetDisplayBounds(displays[0], &rect);
                    position.x = static_cast<int>(fingers[finger]->x * static_cast<float>(rect.w)) + rect.x;
                    position.y = static_cast<int>(fingers[finger]->y * static_cast<float>(rect.h)) + rect.y;
                }
                SDL_free(displays);
            }
            SDL_free(static_cast<void*>(fingers));
        }
    }
    SDL_free(devices);
    return position;
}

Vector2i getTouchPosition(unsigned int finger, const WindowBase& relativeTo)
{
    int          count   = 0;
    SDL_TouchID* devices = SDL_GetTouchDevices(&count);
    Vector2i     position;
    if (devices && count > 0)
    {
        int          fingerCount = 0;
        SDL_Finger** fingers     = SDL_GetTouchFingers(devices[0], &fingerCount);
        if (fingers)
        {
            if (static_cast<int>(finger) < fingerCount)
            {
                int w = 0;
                int h = 0;
                SDL_GetWindowSize(static_cast<SDL_Window*>(relativeTo.getNativeHandle()), &w, &h);
                position.x = static_cast<int>(fingers[finger]->x * static_cast<float>(w));
                position.y = static_cast<int>(fingers[finger]->y * static_cast<float>(h));
            }
            SDL_free(static_cast<void*>(fingers));
        }
    }
    SDL_free(devices);
    return position;
}
} // namespace sf::priv::InputImpl
