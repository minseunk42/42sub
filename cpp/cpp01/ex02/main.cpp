#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string str2 = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str2;
    
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}