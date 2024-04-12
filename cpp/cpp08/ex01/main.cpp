#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(13);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "------------------------" << std::endl;
    Span sp1 = Span(10000);
    std::srand(std::time(0));
    for (int i = 0; i < 10000; ++i)
    {
        unsigned int ui = 0;
        ui--;
        sp1.addNumber(std::rand() % ui);
    }
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    Span sp2 = Span(3);
    sp2 = sp1;
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    Span sp3 = Span(sp2);
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
    return 0;
}