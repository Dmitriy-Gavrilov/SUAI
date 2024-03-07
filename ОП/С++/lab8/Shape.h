#pragma once
// Τΰιλ shape.h
#ifndef SHAPE_H
#define SHAPE_H
#include "screen.h"
class Shape
{
public:
	virtual void draw(Screen* screen) const = 0;
	virtual void move(Point p) = 0;
	virtual Point getLeftTop() const = 0;
	virtual Point getRightTop() const = 0;
	virtual Point getLeftBottom() const = 0;
	virtual Point getRightBottom() const = 0;

	virtual ~Shape() {}
};
#endif // SHAPE_H