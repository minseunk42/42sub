#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

void tr_str(std::string &buf, std::string s1, std::string s2)
{
    std::string temp;
    std::size_t fidx = buf.find(s1);;
    while (fidx != std::string::npos)
    {
        temp = buf.substr(0, fidx);
        temp += s2;
        temp += buf.substr(fidx + s1.length());
        buf = temp;
        fidx = buf.find(s1);
    }
}

int main(int ac, char **av)
{
    if (ac != 4 || std::string(av[2]).empty())
        return -1;
    std::string out_name;
    std::string buf;
    out_name += av[1];
    out_name += ".replace";
    out_name[(int)out_name.length()] = 0;
    std::ofstream fout((&out_name[0]), std::ios_base::out);
    std::ifstream fin((&av[1][0]), std::ios_base::in);
    while (std::getline(fin, buf))
    {
        if (buf.empty())
            break;
        tr_str(buf, std::string(av[2]), std::string(av[3]));
        fout << buf << std::endl;
    }
    fout.close();
    fin.close();
    return 0;
}