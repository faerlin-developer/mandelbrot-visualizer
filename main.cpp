#include <iostream>
#include "screen.h"
#include "buffer.h"
#include "transformer.h"
#include "mandelbrot.h"
#include "julia.h"

void initializeMandelbrot(Mandelbrot *mandelbrot);

void initializeJulia(Julia *julia);

void drawFractal(Fractal *fractal, Screen *screen, Buffer *buffer);

int main(int argc, char *argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 0;
    }

    Screen jScreen{"Julia Visualizer", 400, 300};
    Screen mScreen{"Mandelbrot Visualizer", 800, 600};

    if (!jScreen.init() || !mScreen.init()) {
        std::cout << "ERROR: failed to initialize SDL" << std::endl;
        return 0;
    }

    int windowX, windowY;
    SDL_GetWindowPosition(mScreen.window, &windowX, &windowY);
    SDL_SetWindowPosition(mScreen.window, windowX - 200, windowY);
    SDL_SetWindowPosition(jScreen.window, windowX + 600, windowY + 150);

    Mandelbrot mandelbrot(mScreen.WIDTH, mScreen.HEIGHT, 1000);
    Julia julia(jScreen.WIDTH, jScreen.HEIGHT, 200);
    Buffer mBuffer(mScreen.WIDTH, mScreen.HEIGHT);
    Buffer jBuffer(jScreen.WIDTH, jScreen.HEIGHT);

    initializeMandelbrot(&mandelbrot);
    initializeJulia(&julia);
    drawFractal(&mandelbrot, &mScreen, &mBuffer);
    drawFractal(&julia, &jScreen, &jBuffer);

    int mouseX = 0;
    int mouseY = 0;
    int newMouseX, newMouseY;
    while (true) {

        Uint32 mFlags = SDL_GetWindowFlags(mScreen.window);
        SDL_GetMouseState(&newMouseX, &newMouseY);
        if ((mFlags & SDL_WINDOW_MOUSE_FOCUS) && (newMouseX != mouseX || newMouseY != mouseY)) {
            auto [r, i] = mandelbrot.transformer.toComplex(mouseX, mouseY);
            julia.setC(r, i);
            drawFractal(&julia, &jScreen, &jBuffer);
            mouseX = newMouseX;
            mouseY = newMouseY;
        }

        SDL_Event event;
        if (SDL_PollEvent(&event)) {

            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) {
                break;
            }

            if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                mandelbrot.transformer.moveCenter(mouseX, mouseY);
                mandelbrot.transformer.zoom(0.40);
                drawFractal(&mandelbrot, &mScreen, &mBuffer);
            }

            if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT) {
                mandelbrot.transformer.zoom(2.5);
                drawFractal(&mandelbrot, &mScreen, &mBuffer);
            }

            if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_MIDDLE) {
                mandelbrot.transformer.moveCenter(mouseX, mouseY);
                drawFractal(&mandelbrot, &mScreen, &mBuffer);
            }

            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
                initializeMandelbrot(&mandelbrot);
                initializeJulia(&julia);
                drawFractal(&mandelbrot, &mScreen, &mBuffer);
                drawFractal(&julia, &jScreen, &jBuffer);
            }

        }
    }

    std::cout << "Done!" << std::endl;

    return 0;
}

void initializeMandelbrot(Mandelbrot *mandelbrot) {
    mandelbrot->transformer.setCenter(-0.75, 0);
    mandelbrot->transformer.setScale(3.0 / mandelbrot->transformer.WIDTH);
}

void initializeJulia(Julia *julia) {
    julia->transformer.setCenter(0, 0);
    julia->transformer.setScale(3.0 / julia->transformer.WIDTH);
    julia->setC(0, 0);
}

void drawFractal(Fractal *fractal, Screen *screen, Buffer *buffer) {
    fractal->run(buffer);
    screen->setBuffer(buffer->buffer.get());
    screen->update();
}
