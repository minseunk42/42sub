#include "ScalarConverter.hpp"

static bool isCLiteral(std::string input)
{
    if (input.size() != 1)
        return (false);
    if (input[0] >= '0' && input[0] <= '9')
        return (false);
    return (true);
}

static bool isILiteral(std::string input)
{
    stringstream ss;
    int i;
    ss << input;
    ss >> i;
    if (i == 2147483647 && input != "2147483647")
        return (false);
    if (i == -2147483648 && input != "-2147483648")
        return (false);
    if (input.size() > 10 + (input[0] == '-') + (input[0] == '+')) 
        return (false);
    for (unsigned long i = 0; i < input.size(); ++i)
    {
        if (i == 0 && input[i] == '-')
            continue;
        if (i == 0 && input[i] == '+')
            continue;
        if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    return (true);
}

static bool isFLiteral(std::string input)
{
    int dotCnt = 0;
    for (unsigned long i = 0; i < input.size() - 1; ++i)
    {
        if (i == 0 && input[i] == '-')
            continue;
        if (i == 0 && input[i] == '+')
            continue;
        if (input[i] == '.')
        {
            dotCnt += 1;
            continue;
        }
        if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    if (dotCnt > 1)
        return (false);
    if (input[input.size() - 1] != 'f')
        return (false);
    return (true);
}

static bool isDLiteral(std::string input)
{
    int dotCnt = 0;
    for (unsigned long i = 0; i < input.size(); ++i)
    {
        if (i == 0 && input[i] == '-')
            continue;
        if (i == 0 && input[i] == '+')
            continue;
        if (input[i] == '.')
        {
            dotCnt += 1;
            continue;
        }
        if (input[i] < '0' || input[i] > '9')
            return (false);
    }
    if (dotCnt > 1)
        return (false);
    return (true);
}

static bool isNonPrintable(char c)
{
    if ((c > 31 && c < 127) || (c >= 9 && c <= 13))
        return (false);
    return (true);
}

static void printAll(char c, int i, float f, double d, std::string input)
{
    if (i > 127 || i < 0)
        std::cout << "char : impossible" << std::endl;
    else if (isNonPrintable(c))
        std::cout << "char : Non displayable" << std::endl;
    else 
        std::cout << "char : '" << c << "'" << std::endl;
    if (isOFI(i, input))
        std::cout << "int : impossible" << i << std::endl;
    else
        std::cout << "int : " << i << std::endl;
    
    std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

static bool isNanLiteral(std::string input)
{
    if (input == "nan" || input == "nanf")
        return true;
    return false;
}

static bool isInfLiteral(std::string input)
{
    if (input == "inf" || input == "inff")
        return true;
    return false;
}

static void printNan()
{
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : nanf" << std::endl;
    std::cout << "double : nan" << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    
    char    c;
    int     i;
    float   f;
    double  d;
    std::stringstream ss;
    if (isNanLiteral(input))
    {
        printNan();
        return ;
    }
    else if (isInfLiteral(input))
    {
        f = 1/0.0;
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        printAll(c,i,f,d);
        return ;
    }
    else if (isCLiteral(input))
    {
        c = input[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        printAll(c,i,f,d);
        return ;
    }
    else if (isILiteral(input))
    {
        ss << input;
        ss >> i;
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        printAll(c,i,f,d);
        return ;
    }
    else if (isFLiteral(input))
    {
        input[input.size() - 1] = 0;
        ss << input;
        ss >> f;
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        printAll(c,i,f,d);
        return ;
    }
    else if (isDLiteral(input))
    {
        ss << input;
        ss >> d;
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        printAll(c,i,f,d);
        return ;
    }
    else
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
    }
}
