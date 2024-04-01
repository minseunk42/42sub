#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        unsigned int s;
        T *t;
    public:
        Array();
        Array(unsigned int s);
        Array(Array const &ref);
        Array&  operator=(Array const &ref);
        ~Array();
    public:
        T& operator[](unsigned int i);
        T& operator[](unsigned int i) const;
        unsigned int size() const;

};

#endif