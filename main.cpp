#include <iostream>
#include "screen.h"
#include "mandelbrot.h"
#include "julia.h"
#include "event.h"
#include "config.h"
#include "main.h"

int main(int argc, char *argv[]) {

    Screen mScreen{"Mandelbrot Visualizer", MANDELBROT_WINDOW_WIDTH, MANDELBROT_WINDOW_HEIGHT};
    Screen jScreen{"Julia Visualizer", JULIA_WINDOW_WIDTH, JULIA_WINDOW_HEIGHT};
    if (!jScreen.init() || !mScreen.init()) {
        std::cout << "ERROR: failed to initialize SDL" << std::endl;
        return 0;
    }
    initializeWindowPosition(mScreen.window, jScreen.window);

    Mandelbrot mandelbrot(mScreen.WIDTH, mScreen.HEIGHT, MANDELBROT_MAX_ITERATION);
    initializeMandelbrot(&mandelbrot);
    draw(&mandelbrot, &mScreen);

    Julia julia(jScreen.WIDTH, jScreen.HEIGHT, JULIA_MAX_ITERATION);
    initializeJulia(&julia);
    draw(&julia, &jScreen);

    int mouseX = 0;
    int mouseY = 0;
    int newMouseX, newMouseY;
    while (true) {

        SDL_GetMouseState(&newMouseX, &newMouseY);
        if ((newMouseX != mouseX || newMouseY != mouseY) && mScreen.isWindowInFocus()) {
            auto [re, im] = mandelbrot.transformer.toComplex(mouseX, mouseY);
            julia.setC(re, im);
            draw(&julia, &jScreen);
            mouseX = newMouseX;
            mouseY = newMouseY;
        }

        SDL_Event event;
        if (SDL_PollEvent(&event)) {

            if (Event::windowClosed(event)) {
                break;
            }

            if (Event::leftMouseButtonClicked(event) && mScreen.isWindowInFocus()) {
                mandelbrot.transformer.moveCenter(mouseX, mouseY);
                mandelbrot.transformer.zoom(ZOOM_IN_SCALE);
                draw(&mandelbrot, &mScreen);
            }

            if (Event::rightMouseButtonClicked(event) && mScreen.isWindowInFocus()) {
                mandelbrot.transformer.zoom(ZOOM_OUT_SCALE);
                draw(&mandelbrot, &mScreen);
            }

            if (Event::middleMouseButtonClicked(event) && mScreen.isWindowInFocus()) {
                mandelbrot.transformer.moveCenter(mouseX, mouseY);
                draw(&mandelbrot, &mScreen);
            }

            if (Event::spaceKeyPressed(event)) {
                initializeMandelbrot(&mandelbrot);
                initializeJulia(&julia);
                draw(&mandelbrot, &mScreen);
                draw(&julia, &jScreen);
            }
        }
    }

    mScreen.close();
    jScreen.close();

    return 0;
}

void initializeWindowPosition(SDL_Window *mWindow, SDL_Window *jWindow) {
    int windowX, windowY;
    SDL_GetWindowPosition(mWindow, &windowX, &windowY);
    SDL_SetWindowPosition(mWindow, windowX - 200, windowY);
    SDL_SetWindowPosition(jWindow, windowX + 600, windowY + 150);
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

void draw(Fractal *fractal, Screen *screen) {
    fractal->generate();
    screen->setBuffer(fractal->buffer.pointer.get());
    screen->update();
}
