#pragma once

#include <complex>
#include "fractal.h"

class Mandelbrot : public Fractal {
public:
    Mandelbrot(int width, int height, int maxIterations);

    int getIterations(double x, double y) override;
};




