#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string out_name;
    out_name += av[1];
    out_name += ".replace";
    std::ofstream fout(out_name, std::ios_base::out);
    fout << "123" << std::endl;
    fout.close();
}