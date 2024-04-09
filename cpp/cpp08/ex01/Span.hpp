#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int m_size;
        std::set<unsigned int> m_s;
        Span();
    public:
        Span(unsigned int size);
        Span(Span const &ref);
        Span&  operator=(Span const &ref);
        ~Span();
    public:
        void addNumber(unsigned int);
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif