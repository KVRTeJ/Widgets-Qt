#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>

class Figure {
public:
    Figure(int x, int y, int halflen)
        :x(x), y(y), halflen(halflen)
    {}
    virtual ~Figure() = default;
    void move(float alpha, QPainter *painter);
protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *painter) = 0;
};

class MyLine: public Figure {
public:
    MyLine(int x, int y, int halflen)
        :Figure(x, y, halflen)
    {}
protected:
    void draw(QPainter *painter) override;
};

class MyRect: public Figure {
public:
    MyRect(int x, int y, int halflen)
        :Figure(x, y, halflen)
    {}
protected:
    void draw(QPainter *painter) override;
};

#endif // FIGURE_H
