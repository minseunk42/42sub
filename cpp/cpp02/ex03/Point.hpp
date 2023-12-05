#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
        Point();
        Point(const float x, const float y);
        Point(Point const &f);
        ~Point();
        Point&      operator=(Point const &f);
        Fixed getX(void) const;
        Fixed getY(void) const;
};

#endif