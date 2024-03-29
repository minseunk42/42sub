#include <iostream>

int main()
{
    std::string *a = new std::string[100];
    for (int i = 0; i < 100; ++i)
        std::cout << a[i] << '\n';
}