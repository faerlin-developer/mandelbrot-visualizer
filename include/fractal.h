#pragma once

#include "buffer.h"
#include "transformer.h"

class Fractal {
public:
    int max_iterations;
    CoordinateTransformer transformer;

private:
    std::unique_ptr<int[]> iterations;
    std::unique_ptr<int[]> histogram;
    int total_iterations{0};

public:
    Fractal(int width, int height, int max_iterations);

    void run(Buffer *buffer);

protected:
    void reset();

    void calculateIterationsAndHistogram();

    void calculateFractal(Buffer *buffer);

    virtual int getIterations(double x, double y) = 0;
};











