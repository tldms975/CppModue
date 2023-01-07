#include "Point.hpp"

static float	diffX(Point const a, Point const b)
{
	return (b.getX().toFloat() - a.getX().toFloat());
}

static float	diffY(Point const a, Point const b)
{
	return (b.getY().toFloat() - a.getY().toFloat());
}

static float	lineSection(Point const a, Point const b, Point const point)
{
	return (diffX(point, a) * diffY(a, b) / diffX(a, b) - diffY(point, a));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float la = lineSection(b, c, a);
	float lb = lineSection(c, a, b);
	float lc = lineSection(a, b, c);
	float pointLa = lineSection(b, c, point);
	float pointLb = lineSection(c, a, point);
	float pointLc = lineSection(a, b, point);
	if (la * pointLa > 0 && lb * pointLb > 0 && lc * pointLc > 0)
		return (true);
	else
		return (false);
}