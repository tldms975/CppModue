#include "Point.hpp"

Point::Point()
: _x(0), _y(0)
{

}

Point::Point(const float x, const float y)
: _x(x), _y(y)
{

}

Point::Point(const Point& point)
{
	*this = point;
}

Point::~Point()
{

}

Point& Point::operator=(const Point& point)
{

}
