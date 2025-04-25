#include <math.h>

#include "Figure.h"

void Figure::move(float alpha, QPainter *painter) {
    dx = halflen * cos(alpha);
    dy = halflen * sin(alpha);
    draw(painter);
}

void MyLine::draw(QPainter *painter) {
    painter->drawLine(x + dx, y + dy, x - dx, y - dy);
}

void MyRect::draw(QPainter *painter) {
    painter->drawLine(x + dx, y + dy, x + dy, y - dx);
    painter->drawLine(x + dy, y - dx, x - dx, y - dy);
    painter->drawLine(x - dx, y - dy, x - dy, y + dx);
    painter->drawLine(x - dy, y + dx, x + dx, y + dy);
}
