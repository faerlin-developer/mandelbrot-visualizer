#pragma once

#include <complex>
#include "fractal.h"

class Julia : public Fractal {
public:
    std::complex<double> c;
public:
    Julia(int width, int height, int maxIterations);

    int getIterations(double x, double y) override;

    void setC(double x, double y);
};
