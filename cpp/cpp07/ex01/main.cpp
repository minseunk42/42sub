#include "iter.hpp"
#include <iostream>

template <typename T>
void func1(T &t)
{
    t += 'a' - 'A';
}

template <typename T>
void func2(T &t)
{
    std::cout << t << std::endl;
}

int main( void )
{
    int arr[5] = {0,};
    char arrc[5] = {'A', 'B', 'C', 'D', 'E'};
    ::iter(arr,5,func1<int>);
    ::iter(arr,5,func2<int>);
    ::iter(arrc,5,func1<char>);
    ::iter(arrc,5,func2<char>);
}