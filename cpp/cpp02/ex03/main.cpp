#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
    Point a = Point(3,4);
    Point b = Point(6.3, 9.9);
    Point c = Point(10, 20);
    Point p = Point(5.625,5);

    bsp(a,b,c,p);
    return 0;
}
