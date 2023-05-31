#include "zoomlist.h"
#include <iostream>

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height) {}

void ZoomList::add(const Zoom &zoom) {
    zooms.push_back(zoom);
    xCenter += (zoom.x - m_width / 2) * m_scale;
    yCenter += (zoom.y - m_height / 2) * m_scale;
    m_scale *= zoom.scale;
    std::cout << "m_scale" << m_scale << std::endl;
}

std::pair<double, double> ZoomList::doZoom(int x, int y) {

    double xFractal = (x - m_width / 2) * m_scale + xCenter;
    double yFractal = (y - m_height / 2) * m_scale + yCenter;

    return {xFractal, yFractal};
}

void ZoomList::zoomOut(double factor) {
    m_scale /= factor;
}

void ZoomList::set(const Zoom &zoom) {
    xCenter = zoom.x - m_width / 2;
    yCenter = zoom.y - m_height / 2;
    m_scale = zoom.scale;
}
