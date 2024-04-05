#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int size;
        std::set<unsigned int> s;
        Span();
    public:
        Span(unsigned int size);
        Span(Span const &ref);
        Span&  operator=(Span const &ref);
        ~Span();
    public:
        void addNumber();
        unsigned int shortestSpan();
        unsigned int longestSpan();

}

#endif