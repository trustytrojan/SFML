#pragma once
#include <SFML/Window/Keyboard.hpp>

#include <SDL3/SDL.h>

namespace sf::priv
{
Keyboard::Key      sdlKeyToSfml(SDL_Keycode key);
SDL_Keycode        sfmlKeyToSdl(Keyboard::Key key);
Keyboard::Scancode sdlScancodeToSfml(SDL_Scancode code);
SDL_Scancode       sfmlScancodeToSdl(Keyboard::Scancode code);
} // namespace sf::priv
