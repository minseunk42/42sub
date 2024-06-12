#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    try {
        if (ac < 2)
            throw PmergeMe::InputIsWrong();
        PmergeMe pm;
        int i = 0;
        while (++i < ac)
            pm.add(av[i]);
        pm.sort();
    }
    catch (std::exception &e) {
		std::cout << e.what() << std::endl;
        return -1;
	}
}
