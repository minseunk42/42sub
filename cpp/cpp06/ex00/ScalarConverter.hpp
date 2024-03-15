#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &ref);
        ScalarConverter&  operator=(ScalarConverter const &ref);
    public:
        ~ScalarConverter();
        static void convert(std::string input);
};

#endif