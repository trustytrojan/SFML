#include <SFML/Window/VideoModeImpl.hpp>

#include <SDL3/SDL.h>

namespace sf::priv
{
std::vector<VideoMode> VideoModeImpl::getFullscreenModes()
{
    std::vector<VideoMode> modes;
    int                    count    = 0;
    SDL_DisplayID*         displays = SDL_GetDisplays(&count);
    if (displays && count > 0)
    {
        int               modeCount    = 0;
        SDL_DisplayMode** displayModes = SDL_GetFullscreenDisplayModes(displays[0], &modeCount);
        if (displayModes)
        {
            for (int i = 0; i < modeCount; ++i)
            {
                modes.emplace_back(Vector2u(static_cast<unsigned int>(displayModes[i]->w),
                                            static_cast<unsigned int>(displayModes[i]->h)),
                                   32);
            }
            SDL_free(static_cast<void*>(displayModes));
        }
    }
    SDL_free(static_cast<void*>(displays));
    return modes;
}

VideoMode VideoModeImpl::getDesktopMode()
{
    int            count    = 0;
    SDL_DisplayID* displays = SDL_GetDisplays(&count);
    if (displays && count > 0)
    {
        const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(displays[0]);
        if (mode)
        {
            VideoMode desktopMode(Vector2u(static_cast<unsigned int>(mode->w), static_cast<unsigned int>(mode->h)), 32);
            SDL_free(static_cast<void*>(displays));
            return desktopMode;
        }
    }
    SDL_free(static_cast<void*>(displays));
    return VideoMode(Vector2u(800, 600), 32);
}
} // namespace sf::priv
