#include "easyfind.hpp"
#include <vector>
#include <list>
#include <stack>

int main()
{
    //vector
    std::vector<int> v;
    std::vector<int>::iterator itv;
    try{itv = easyfind(v, 42);}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    try
    {
        v.push_back(42);
        itv = easyfind(v, 42);
        std::cout << *itv << '\n';
    }
    catch(const std::exception& e){std::cerr << e.what() << '\n';}

    //list
    std::list<int> l;
    std::list<int>::iterator itl;
    try{itl = easyfind(l, 42);}
    catch(const std::exception& e){std::cerr << e.what() << '\n';}
    try
    {
        l.push_back(42);
        itl = easyfind(l, 42);
        std::cout << *itl << '\n';
    }
    catch(const std::exception& e){std::cerr << e.what() << '\n';}

    // stack
    // std::stack<int> s;
    // std::stack<int>::iterator its;
}