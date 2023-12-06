#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
    Point a = Point(1,1);
    Point b = Point(1, 5);
    Point c = Point(5, 5);
    Point p = Point(3,3);

    std::cout << bsp(a,b,c,p) << std::endl;
    return 0;
}
