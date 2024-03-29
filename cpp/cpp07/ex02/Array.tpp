#include "Array.hpp"

template <typename T>

Array<T>::Array()
{
    this->s = 0;
    t = new T();
}

template <typename T>

Array<T>::Array(int s)
{
    this->s = s;
    if (s == 0)
        t = new T();
    else
        t = new T[s];
}

template <typename T>

Array<T>::Array(Array const &ref)
{
    t = new T[ref.size()];
    s = ref.size();
    for (int i = 0; i < s; ++i)
        t[i] = ref[i];
}

template <typename T>

Array<T>&  Array<T>::operator=(Array const &ref)
{
    if (this == &ref)
        return *this;
    delete[] t;
    t = new T[this->s];
    for (int i = 0; i < s; ++i)
        t[i] = ref[i];
    return *this;
}

template <typename T>

T& Array<T>::operator[](int i)
{
    if (i< 0 || i >= this->s)
        throw Array<T>::IndexOutOfRangeException();
    return t[i];
}

template <typename T>

T& Array<T>::operator[](int i) const
{
    if (i< 0 || i >= this->s)
        throw Array<T>::IndexOutOfRangeException();
    return t[i];
}

template <typename T>

Array<T>::~Array()
{
    delete[] t;
}

template <typename T>

int Array<T>::size() const
{
    return this->s;
}