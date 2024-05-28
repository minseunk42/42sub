#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Error: arg is wrong." << std::endl;
        return -1;
    }
    char df[] = "data.csv";
    try
    {
        BitcoinExchange be(df);
        be.exchange(av[1]);
    }
    catch (std::exception &e) 
    {
		std::cout << e.what() << std::endl;
        return -1;
	}
    return 0;
}
