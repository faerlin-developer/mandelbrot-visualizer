#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include "zoom.h"
#include <vector>
#include <utility>

class ZoomList {
public:
    double xCenter{0};
    double yCenter{0};
private:
    double m_scale{1.0};
    int m_width{0};
    int m_height{0};
    std::vector<Zoom> zooms;
public:
    ZoomList(int width, int height);

    void add(const Zoom &zoom);

    std::pair<double, double> doZoom(int x, int y);

    void zoomOut(double scale);

    void set(const Zoom &zoom);

};

#endif
