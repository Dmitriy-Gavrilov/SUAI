#pragma once
#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Line.h"
#include "Reflectable.h"
#include "Rotatable.h"

class Parallelogram: public virtual Shape, public virtual Reflectable, public virtual Rotatable
{
protected:
	Line* _left, * _top, * _right, * _bottom;

public:
	Parallelogram(const Point& x1, const Point& x2, const Point& x3, const Point& x4);

	virtual void draw(Screen* screen) const;

	virtual void move(Point p);

	Point getLeftTop() const;
	Point getRightTop() const;
	Point getLeftBottom() const;
	Point getRightBottom() const;

	virtual void  flipHorisontally();
	virtual void  flipVertically();

	virtual void rotateLeft();
	virtual void rotateRight();

	virtual ~Parallelogram();

};

#endif //PARALLELOGRAM_H