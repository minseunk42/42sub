#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string str;
    for (int i = 1; i < ac; i++)str += av[i];
    for (unsigned long i = 0; i < str.length(); i++)str[i] = toupper(str[i]);
    if (ac == 1)str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << str << std::endl;
    return 0;
}
