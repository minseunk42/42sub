#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data t;
    t.i = 42;
    t.f = 42.0;
    Data *out = Serializer::deserialize(Serializer::serialize(&t));
    // Data *wout = Serializer::deserialize(123);
    // std::cout << wout->i <<std::endl;
    std::cout << out->i <<std::endl;
    std::cout << out->f <<std::endl;
    t.i = 0;
    std::cout << out->i <<std::endl;
    std::cout << out->f <<std::endl;
}