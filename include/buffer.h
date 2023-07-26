#pragma once

#include <memory>

class Buffer {
public:
    int WIDTH;
    int HEIGHT;
    std::unique_ptr<uint32_t> pointer;
public:
    Buffer(int width, int height);

    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};





