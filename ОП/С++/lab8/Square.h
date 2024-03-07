#pragma once
//Τΰιλ square.h
#ifndef SQUARE_H
#define SQUARE_H
#include "line.h"
class Square : public virtual Shape
{
public:
	Square(const Point& leftTop, const Point& rightBottom);
	virtual void draw(Screen* screen) const;
	virtual void move(Point p);
	Point getLeftTop() const;
	Point getRightTop() const;
	Point getLeftBottom() const;
	Point getRightBottom() const;
	virtual ~Square();
protected:
	Line* _left, * _top, * _right, * _bottom;
};

#endif //SQUARE_H