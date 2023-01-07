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
: _x(point.getX()), _y(point.getY())
{
}

Point::~Point()
{

}

Point& Point::operator=(const Point& point)
{
	(void)point;
	std::cout << "Can't assign a point\n";
	return (*this);
}

Fixed const& Point::getX(void) const
{
	return (this->_x);
}

Fixed const& Point::getY(void) const
{
	return (this->_y);
}
