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
    if (input.size() > 10 + (input[0] == '-')) 
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

static void printAll(char c, int i, long l, float f, double d, bool is_int)
{
    if (i > 127 || i < 0)
        std::cout << "char : impossible" << std::endl;
    else if (c < 9 || c > 126)
        std::cout << "char : Non displayable" << std::endl;
    else 
        std::cout << "char : '" << c << "'" << std::endl;
    if (l != i)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << i << std::endl;
    if (is_int == true)
    {
        std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    else
    {
        std::cout << "float : "  << f << "f" << std::endl;
        std::cout << "double : " << d << std::endl;    
    }
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
    if (input == "nan")
    {
        printNan();
        return ;
    }
    char    c;
    int     i;
    long    l;
    float   f;
    double  d;
    std::stringstream ss;
    std::stringstream ss1;
    if (isCLiteral(input))
    {
        c = input[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        l = static_cast<long>(d);
        printAll(c,i,l,f,d,true);
        return ;
    }
    else if (isILiteral(input))
    {
        ss << input;
        ss >> i;
        ss1 << input;
        ss1 >> l;
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        printAll(c,i,l,f,d,true);
        return ;
    }
    else if (isFLiteral(input))
    {
        input[input.size() - 1] = 0;
        ss << input;
        std::cout << input << std::endl;
        ss >> f;
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        l = static_cast<long>(f);
        printAll(c,i,l,f,d,false);
        return ;
    }
    else if (isDLiteral(input))
    {
        ss << input;
        ss >> d;
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        l = static_cast<long>(d);
        printAll(c,i,l,f,d,false);
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
