#include <complex>
#include "mandelbrot.h"
#include "fractal.h"

Mandelbrot::Mandelbrot(int width, int height, int maxIterations) : Fractal(width, height, maxIterations) {}

/*
int MandelbrotOld::getIterations(double x, double y) {

    std::complex<double> z(x, y);
    std::complex<double> c(-0.5251993, -0.5251993);

    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        z = z * z + c;
        if (std::abs(z) > 2) {
            break;
        }

        iterations++;
    }

    // https://www.geogebra.org/m/mfewjrek
    // https://math.libretexts.org/Bookshelves/Analysis/Complex_Analysis_-_A_Visual_and_Interactive_Introduction_(Ponce_Campuzano)/05%3A_Chapter_5/5.06%3A_The_Julia_Set

    return iterations;
}
 */

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
