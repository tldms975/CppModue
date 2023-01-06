#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point::Point();
		Point::Point(const float x, const float y);
		Point::~Point();
		Point::Point(const Point& point);
		Point& operator=(const Point& point);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif