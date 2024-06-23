#include <iostream>
#include <string>

// int main(int ac, char **av)
// {
//     std::string str;
//     for (int i = 1; i < ac; i++)str += av[i];
//     for (unsigned long i = 0; i < str.length(); i++)str[i] = toupper(str[i]);
//     if (ac == 1)str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
//     std::cout << str << std::endl;
//     return 0;
// }

int main(int ac, char** av) {
    std::string s;
    for (int i = 1; i < ac; s += av[i++]);
    for (int i = 0; i < s.size(); s[i++] = toupper(s[i]));
    std::cout << (ac == 1 ? "* LOUD AND UNBEARABLE FEEDBACK NOISE *" : s) << std::endl;
    return 0;
}