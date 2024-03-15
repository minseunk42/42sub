#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate() {
    std::srand(std::time(0));
    switch (std::rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        Base &t = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)t;
    } catch (...) {}
    try {
        Base &t = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)t;
    } catch (...) {}
    try {
        Base &t = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)t;
    } catch (...) {}
    
}

int main() 
{
    Base* obj = generate();
    identify(*obj);
    identify(obj);
    delete obj;
    return 0;
}