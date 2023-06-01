#pragma once

#include <string>
#include <SDL.h>

class Screen {
private:
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;

public:
    const std::string TITLE;
    const int WIDTH;
    const int HEIGHT;
    SDL_Window *window;

public:
    Screen(std::string title, int width, int height);

    bool init();

    void update();

    void setBuffer(Uint32 *buffer);

    bool isWindowInFocus();

    void close();
};