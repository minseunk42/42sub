#include "RPN.hpp"

int main(int ac, char *av[])
{
    try {
        RPN rpn;
        if (ac != 2)
            throw RPN::InputIsWrong();
        rpn.cal(av[1]);
    }
    catch (std::exception &e) {
		std::cout << e.what() << std::endl;
        return -1;
	}
    return 0;
}