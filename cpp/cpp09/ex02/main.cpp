#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    try {
        if (ac < 2)
            throw PmergeMe::InputIsWrong();
        PmergeMe pm;
        while (--ac)
            pm.add(av[ac]);
        pm.sort();
    }
    catch (std::exception &e) {
		std::cout << e.what() << std::endl;
        return -1;
	}
}