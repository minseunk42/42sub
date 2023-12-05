#include "Point.hpp"

Point::Point()
{
    this->x = Fixed();
    this->y = Fixed();
}

Point::Point(const float x, const float y)
{
    this->x = Fixed(x);
    this->y = Fixed(y);
}

Point::Point(Point const &p)
{
    *this = p;
}

Point::~Point(){}

Point&      Point::operator=(Point const &p)
{
    this->x = p.x;
    this->y = p.y;
    return *this;
}

Fixed Point::getX(void) const
{
    return this->x;
}

Fixed Point::getY(void) const
{
    return this->y;
}
