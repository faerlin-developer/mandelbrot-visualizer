#include <complex>
#include "mandelbrot.h"
#include "fractal.h"

Mandelbrot::Mandelbrot(int width, int height, int maxIterations) : Fractal(width, height, maxIterations) {}

int Mandelbrot::getIterations(double x, double y) {

    std::complex<double> z = 0;
    std::complex<double> c(x, y);

    int iterations = 0;

    while (iterations < this->max_iterations) {
        z = z * z + c;
        if (std::abs(z) > 2) {
            break;
        }

        iterations++;
    }

    return iterations;
}
