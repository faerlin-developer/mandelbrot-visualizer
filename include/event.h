#pragma once

#include <SDL.h>

class Event {
public:
    static bool windowClosed(SDL_Event &event);

    static bool leftMouseButtonClicked(SDL_Event &event);

    static bool rightMouseButtonClicked(SDL_Event &event);

    static bool middleMouseButtonClicked(SDL_Event &event);

    static bool spaceKeyPressed(SDL_Event &event);

};
