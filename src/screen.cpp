#include <iostream>
#include <string>
#include <cstring>
#include <SDL.h>
#include "screen.h"

Screen::Screen(std::string title, int width, int height) :
        TITLE(title), WIDTH(width), HEIGHT(height),
        window{nullptr}, m_renderer{nullptr},
        m_texture{nullptr}, m_buffer{nullptr} {}

bool Screen::init() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    window = SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!m_renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);
    if (!m_texture) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    m_buffer = new Uint32[WIDTH * HEIGHT];
    memset(m_buffer, 0, WIDTH * HEIGHT * sizeof(Uint32));

    return true;
}

void Screen::update() {
    SDL_UpdateTexture(m_texture, nullptr, m_buffer, WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
}

void Screen::close() {

    delete[] m_buffer;
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::setBuffer(Uint32 *buffer) {
    std::memcpy(m_buffer, buffer, WIDTH * HEIGHT * sizeof(Uint32));
}

bool Screen::isWindowInFocus() {
    Uint32 mFlags = SDL_GetWindowFlags(window);
    return mFlags & SDL_WINDOW_MOUSE_FOCUS;
}
