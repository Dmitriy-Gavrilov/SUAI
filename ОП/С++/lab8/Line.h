#pragma once
// Τΰιλ line.h
#ifndef LINE_H
#define LINE_H
#include "shape.h"
#include "screen.h"
#include <algorithm>
class Line : public Shape
{
protected:
	Point _a;
	Point _b;
public:
	Line(const Point& a, const Point& b);
	Line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);
	Line(const Line& source);
	void draw(Screen* screen) const;
	void move(Point p);
	Point getLeftTop() const;
	Point getRightTop() const;
	Point getLeftBottom() const;
	Point getRightBottom() const;
	Point getFirstPoint() const;
	Point getSecondPoint() const;
};

#endif // LINE_H
