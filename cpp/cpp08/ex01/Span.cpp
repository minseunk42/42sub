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
    this->m_size = ref.m_size;
}

Span&  Span::operator=(Span const &ref)
{
    if (this != &ref)
    {
        m_s.clear();
        this->m_size = ref.m_size;
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
    return m_size;
}

unsigned int Span::longestSpan()
{
    if (m_s.size() < 2)
        throw std::exception();
    return (*m_s.rbegin() - *m_s.begin());
}