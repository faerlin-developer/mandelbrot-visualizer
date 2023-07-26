#pragma once

#include <SDL.h>
#include "fractal.h"
#include "mandelbrot.h"
#include "julia.h"
#include "screen.h"

void initializeWindowPosition(SDL_Window *mWindow, SDL_Window *jWindow);

void initializeMandelbrot(Mandelbrot *mandelbrot);

void initializeJulia(Julia *julia);

void draw(Fractal *fractal, Screen *screen);
