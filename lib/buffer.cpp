#include <cstring>
#include "buffer.h"

Buffer::Buffer(int width, int height) :
        WIDTH(width),
        HEIGHT(height),
        buffer(new uint32_t[WIDTH * HEIGHT]()) {}

void Buffer::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }

    uint32_t color = 0;
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;

    // origin is the top left corner
    // with the positive x-direction going from left to right
    // and positive y-direction going from top to bottom
    buffer.get()[(y * WIDTH) + x] = color;
}

void Buffer::reset() {
    std::memset(buffer.get(), 0, WIDTH * HEIGHT * sizeof(uint32_t));
}
