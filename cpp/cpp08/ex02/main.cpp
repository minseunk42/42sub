#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size = " <<  mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "-------------------" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::list<int>::iterator tmp = l.begin();
    ++tmp;
    std::cout << *tmp << std::endl;
    //std::cout << l.front() << std::endl;
    l.erase(tmp);
    std::cout << "size = " << l.size() << std::endl;
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    std::list<int>::iterator itl = l.begin();
    std::list<int>::iterator itle = l.end();
    ++itl;
    --itl;
    while (itl != itle)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }
    std::cout << "-------------------" << std::endl;
    std::stack<int> s(mstack);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << "-------------------" << std::endl;
    MutantStack<int> cs(mstack);
    it = cs.begin();
    ite = cs.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    mstack.pop();
    std::cout << "-------------------" << std::endl;
    it = cs.begin();
    ite = cs.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    return 0;
}