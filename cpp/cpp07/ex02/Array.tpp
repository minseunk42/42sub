#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->t = new T[0];
    this->s = 0;
}

template <typename T>
Array<T>::Array(unsigned int s)
{
    this->s = s;
    t = new T[s];
}

template <typename T>
Array<T>::Array(Array const &ref)
{
    this->t = new T[ref.size()];
    this->s = ref.size();
    for (unsigned int i = 0; i < s; ++i)
        t[i] = ref[i];
}

template <typename T>
Array<T>&  Array<T>::operator=(Array const &ref)
{
    if (this == &ref)
        return *this;
    delete[] t;
    this->t = new T[this->s];
    for (int i = 0; i < s; ++i)
        t[i] = ref[i];
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= this->s)
        throw std::exception();
    return t[i];
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
    if (i >= this->s)
        throw std::exception();
    return t[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] t;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->s;
}