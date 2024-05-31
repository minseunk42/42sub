#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <sstream>
# include <ctime>

class PmergeMe
{
    private:
        PmergeMe(PmergeMe const &ref){(void)ref;};
        PmergeMe&  operator=(PmergeMe const &ref){(void)ref; return *this;};
        std::vector<unsigned int> v;
        std::list<unsigned int> l;
    public:
        PmergeMe(){};
        ~PmergeMe(){};
        void add(char *val);
        void sort();
    public:
        class InputIsWrong : public std::exception 
        {
            virtual const char* what() const throw()
            {
                return "Error: Input Is Wrong";
            }
        };
};

#endif