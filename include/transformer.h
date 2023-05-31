#pragma once

#include <utility>
#include <memory>

// Between Pixel and Complex plane
class CoordinateTransformer {
public:
    const int WIDTH;
    const int HEIGHT;
private:
    double xCenter{0}; // in complex plane
    double yCenter{0}; // in complex plane
    double scale{1.0};
public:
    CoordinateTransformer(int width, int height);

    void moveCenter(int xPixel, int yPixel);

    void setCenter(double xComplex, double yComplex);

    void zoom(double scale);

    void setScale(double scale);

    std::pair<double, double> toComplex(int xPixel, int yPixel);

};