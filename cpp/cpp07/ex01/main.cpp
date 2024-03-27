#include "iter.hpp"
#include <iostream>

void func(int &a)
{
    a += 10;
}

void func2(char &a)
{
    a -= 'a' - 'A';
}

int main( void )
{
    int arr[5] = {0,};
    char arrc[5] = {'a', 'b', 'c', 'd', 'e'};
    ::iter(arr,5,func);
    std::cout << arr[3] << '\n';
    ::iter(arrc,5,func2);
    for (int i = 0; i < 5; ++i)
        std::cout << arrc[i] << '\n';
}