#include "Screen.h"
Screen::Screen(std::uint32_t xSize, std::uint32_t ySize)
{
	_xSize = xSize;
	_ySize = ySize;
	_screen.reserve(ySize);
	for (size_t i = 0; i < ySize; i++)
		_screen.emplace_back(std::vector<Pixel>(xSize, Pixel::WHITE));
}
void Screen::putLine(const Point& a, const Point& b)
{
	putLine(a.getX(), a.getY(), b.getX(), b.getY());
}
void Screen::putLine(std::uint32_t x0, std::uint32_t y0, std::uint32_t x1, std::uint32_t
	y1)
{
	std::int32_t dx = 1;
	std::int32_t a = x1 - x0;
	if (a < 0) { dx = -1; a = -a; }
	std::int32_t dy = 1;
	std::int32_t b = y1 - y0;
	if (b < 0) { dy = -1; b = -b; }
	std::int32_t two_a = 2 * a;
	std::int32_t two_b = 2 * b;
	std::int32_t xcrit = -b + two_a;
	std::int32_t eps = 0;
	while (true)
	{
		putPoint(x0, y0);
		if (x0 == x1 && y0 == y1) break;
		if (eps <= xcrit)
		{
			x0 += dx;
			eps += two_b;
		}
		if (eps >= a || a < b)
		{
			y0 += dy;
			eps -= two_a;
		}
	}
}
void Screen::putPoint(const Point& p)
{
	_screen[p.getX()][p.getY()] = Pixel::BLACK;
}
void Screen::putPoint(const std::uint32_t x, const std::uint32_t y)
{
	_screen[x][y] = Pixel::BLACK;
}
void Screen::clear()
{
	for (size_t i = 0; i < _ySize; ++i)
		for (size_t j = 0; j < _xSize; ++j)
			_screen[i][j] = Pixel::WHITE;
}
void Screen::draw() const
{
	for (size_t i = 0; i < _ySize; ++i)
	{
		for (size_t j = 0; j < _xSize; ++j)
			std::cout << (char)_screen[i][j];
		std::cout << std::endl;
	}
}