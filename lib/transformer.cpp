#include <complex>
#include "transformer.h"

CoordinateTransformer::CoordinateTransformer(int width, int height) : WIDTH(width), HEIGHT(height) {}

void CoordinateTransformer::moveCenter(int xPixel, int yPixel) {
    xCenter += (xPixel - WIDTH / 2) * scale;
    yCenter += (yPixel - HEIGHT / 2) * scale;
}

void CoordinateTransformer::setCenter(double xComplex, double yComplex) {
    xCenter = xComplex;
    yCenter = yComplex;
}

void CoordinateTransformer::zoom(double scale) {
    this->scale *= scale;
}

std::pair<double, double> CoordinateTransformer::toComplex(int xPixel, int yPixel) {
    double xFractal = (xPixel - WIDTH / 2) * scale + xCenter;
    double yFractal = (yPixel - HEIGHT / 2) * scale + yCenter;
    return {xFractal, yFractal};
}

void CoordinateTransformer::setScale(double scale) {
    this->scale = scale;
}
