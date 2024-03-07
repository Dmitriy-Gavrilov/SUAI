#include "Parallelogram.h"

Parallelogram::Parallelogram(const Point& x1, const Point& x2, const Point& x3, const Point& x4) {
	_left = new Line(x1, x2);
	_top = new Line(x2, x3);
	_right = new Line(x3, x4);
	_bottom = new Line(x1, x4);
}

void Parallelogram::draw(Screen* screen) const
{
	_left->draw(screen);
	_top->draw(screen);
	_right->draw(screen);
	_bottom->draw(screen);
}

void Parallelogram::move(Point p)
{
	_left->move(p);
	_top->move(p);
	_right->move(p);
	_bottom->move(p);
}

Point Parallelogram::getLeftTop() const
{
	return _left->getLeftTop();
}
Point Parallelogram::getRightTop() const
{
	return _right->getRightTop();
}
Point Parallelogram::getLeftBottom() const
{
	return _left->getLeftBottom();
}
Point Parallelogram::getRightBottom() const
{
	return _right->getRightBottom();
}
Parallelogram::~Parallelogram() {
	delete _left;
	delete _top;
	delete _right;
	delete _bottom;
};

void Parallelogram::flipHorisontally()
{
	Point leftTop = _left->getLeftTop();
	Point rightTop = _right->getRightTop();
	Point leftBottom = _left->getLeftBottom();
	Point rightBottom = _right->getRightBottom();

	delete _left;
	delete _right;

	_left = new Line(rightTop, leftTop);
	_right = new Line(rightBottom, leftBottom);
}

void Parallelogram::flipVertically()
{
	Point leftTop = _left->getLeftTop();
	Point rightTop = _right->getRightTop();
	Point leftBottom = _left->getLeftBottom();
	Point rightBottom = _right->getRightBottom();

	delete _left;
	delete _right;

	_left = new Line(leftBottom, leftTop);
	_right = new Line(rightBottom, rightTop);
}

void Parallelogram::rotateLeft()
{
	Point leftTop = _left->getLeftTop();
	Point rightTop = _right->getRightTop();
	Point leftBottom = _left->getLeftBottom();
	Point rightBottom = _right->getRightBottom();

	delete _left;
	delete _right;

	_left = new Line(leftBottom, leftTop);
	_right = new Line(rightBottom, rightTop);
}

void Parallelogram::rotateRight()
{
	Point leftTop = _left->getLeftTop();
	Point rightTop = _right->getRightTop();
	Point leftBottom = _left->getLeftBottom();
	Point rightBottom = _right->getRightBottom();

	delete _left;
	delete _right;

	_left = new Line(rightTop, rightBottom);
	_right = new Line(leftTop, leftBottom);
}



