#include "event.h"

bool Event::windowClosed(SDL_Event &event) {
    return event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE;
}

bool Event::leftMouseButtonClicked(SDL_Event &event) {
    return event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT;
}

bool Event::rightMouseButtonClicked(SDL_Event &event) {
    return event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT;
}

bool Event::middleMouseButtonClicked(SDL_Event &event) {
    return event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_MIDDLE;
}

bool Event::spaceKeyPressed(SDL_Event &event) {
    return event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE;
}
