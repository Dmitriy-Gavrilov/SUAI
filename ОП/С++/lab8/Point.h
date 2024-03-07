#pragma once
//Файл point.h
#ifndef POINT_H
#define POINT_H
#include <cstdint>
class Point //Точка на экране
{
public:
	Point() : _x(0), _y(0) { };
	Point(std::uint32_t x, std::uint32_t y) : _x(x), _y(y) {}
	std::uint32_t getX() const { return _x; }
	std::uint32_t getY() const { return _y; }
	void setX(std::uint32_t val) { _x = val; }
	void setY(std::uint32_t val) { _y = val; }
protected:
	std::uint32_t _x, _y;
};
#endif // POINT_H