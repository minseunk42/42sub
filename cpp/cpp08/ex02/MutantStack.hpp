#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(MutantStack const & ref) 
        {    
            for (MutantStack<T>::const_iterator it = ref.begin(); it != ref.end(); it++)
                (*this).push(*it);
        };
        MutantStack& operator=(MutantStack const & ref) 
        {
            if (this != &ref)
            {
                for (MutantStack<T>::const_iterator it = ref.begin(); it != ref.end(); it++)
                    (*this).push(*it);
            }
            return *this;
        };
        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
        typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}
        typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator rbegin() const {return this->c.rbegin();}
        const_reverse_iterator rend() const {return this->c.rend();}
};

#endif