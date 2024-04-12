#include "Span.hpp"

Span::Span(){}
Span::~Span(){}

Span::Span(unsigned int size)
{
    m_size = size;
}

Span::Span(Span const &ref)
{
    m_s.clear();
    m_size = ref.m_size;
    for (std::set<unsigned int>::iterator it = ref.m_s.begin(); it != ref.m_s.end(); it++)
        m_s.insert(*it);
}

Span&  Span::operator=(Span const &ref)
{
    if (this != &ref)
    {
        m_s.clear();
        m_size = ref.m_size;
        for (std::set<unsigned int>::iterator it = ref.m_s.begin(); it != ref.m_s.end(); it++)
            m_s.insert(*it);
    }
    return *this;
}

void Span::addNumber(unsigned int n)
{
    if (m_s.find(n) != m_s.end())
        throw std::exception();
    m_s.insert(n);
    if (m_size < m_s.size())
        throw std::exception();
}

unsigned int Span::shortestSpan()
{
    if (m_s.size() < 2)
        throw std::exception();
    unsigned int ss = 0;
    ss--;
    for (std::set<unsigned int>::iterator it = m_s.begin(); it != m_s.end(); it++)
    {
        std::set<unsigned int>::iterator temp = ++it;it--;
        if (ss > (*temp - *it))
            ss = (*temp - *it);
    }
    return ss;
}

unsigned int Span::longestSpan()
{
    if (m_s.size() < 2)
        throw std::exception();
    return (*m_s.rbegin() - *m_s.begin());
}
