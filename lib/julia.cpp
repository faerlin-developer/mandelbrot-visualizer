
#include "julia.h"

Julia::Julia(int width, int height, int maxIterations) : Fractal(width, height, maxIterations), c(0, 0) {}

int Julia::getIterations(double x, double y) {

    std::complex<double> z(x, y);

    int iterations = 0;
    while (iterations < this->max_iterations) {
        z = z * z + this->c;
        if (std::abs(z) > 2) {
            break;
        }

        iterations++;
    }

    return iterations;
}

void Julia::setC(double x, double y) {
    c = std::complex(x, y);
}
