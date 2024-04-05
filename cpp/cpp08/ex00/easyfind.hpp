#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

template <typename T>

typename T::iterator easyfind(T& cont, int i)
{
    typename T::iterator it = std::find(cont.begin(), cont.end(), i);
    if (it == cont.end())
        throw std::exception();
    else
        return it;
}

#endif