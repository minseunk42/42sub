#include "Fixed.hpp"
#include "Point.hpp"

static Fixed dot(Point a, Point b)
{
    return Fixed(a.getX() * b.getX() + a.getY() * b.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Point d1 = Point(Fixed(b.getX() - a.getX()).toFloat(), Fixed(b.getY() - a.getY()).toFloat());
    Point d2 = Point(Fixed(c.getX() - a.getX()).toFloat(), Fixed(c.getY() - a.getY()).toFloat());
    Point p = Point(Fixed(point.getX() - a.getX()).toFloat(), Fixed(point.getY() - a.getY()).toFloat());

    Fixed a1 = dot(d1, d1);
    Fixed b1 = dot(d1, d2);
    Fixed c1 = dot(d1, p);
    Fixed a2 = dot(d1, d2);
    Fixed b2 = dot(d2, d2);
    Fixed c2 = dot(d2, p);

    Fixed denom = a1 * b2 - a2 * b1;
    Fixed x = (c1 * b2 - c2 * b1) / denom;
    Fixed y = (a1 * c2 - a2 * c1) / denom;

    if (x < 0 || x > 1)
        return 0;
    if (y < 0 || y > 1)
        return 0;
    if (x + y > 1)
        return 0;
    return 1;
}