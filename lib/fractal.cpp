#include <cstring>
#include <cmath>
#include "fractal.h"
#include "buffer.h"

Fractal::Fractal(int width, int height, int max_iterations) :
        max_iterations(max_iterations),
        transformer(width, height),
        iterations(new int[transformer.WIDTH * transformer.HEIGHT]()),
        histogram(new int[max_iterations]()) {}

void Fractal::run(Buffer *buffer) {
    reset();
    calculateIterationsAndHistogram();
    calculateFractal(buffer);
}

void Fractal::reset() {
    total_iterations = 0;
    std::memset(histogram.get(), 0, max_iterations * sizeof(int));
    std::memset(iterations.get(), 0, transformer.WIDTH * transformer.HEIGHT * sizeof(int));
}

void Fractal::calculateIterationsAndHistogram() {

    for (int y = 0; y < transformer.HEIGHT; y++) {
        for (int x = 0; x < transformer.WIDTH; x++) {
            auto [xComplex, yComplex] = transformer.toComplex(x, y);
            int iteration = getIterations(xComplex, yComplex);
            iterations[y * transformer.WIDTH + x] = iteration;
            if (iteration != max_iterations) {
                histogram[iteration]++;
                total_iterations++;
            }
        }
    }
}

void Fractal::calculateFractal(Buffer *buffer) {

    for (int y = 0; y < transformer.HEIGHT; y++) {
        for (int x = 0; x < transformer.WIDTH; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            int iteration = iterations[y * transformer.WIDTH + x];

            if (iteration < max_iterations) {
                double hue = 0.0;
                for (int i = 0; i <= iteration; i++) {
                    hue += ((double) histogram[i]) / total_iterations;
                }

                red = pow(255, hue);
                green = red;
                blue = 255;
            }

            buffer->setPixel(x, y, red, green, blue);
        }
    }
}

