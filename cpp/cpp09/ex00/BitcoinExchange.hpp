#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <sstream>
# include <exception>
# include <map>

class BitcoinExchange
{
    private:
        BitcoinExchange(){};
        BitcoinExchange(BitcoinExchange const &ref){(void)ref;};
        BitcoinExchange&  operator=(BitcoinExchange const &ref){(void)ref; return *this;};
        std::map<std::string, float> data;
    public:
        ~BitcoinExchange(){};
        BitcoinExchange(char *datafile);
        void exchange(char *);
};

#endif