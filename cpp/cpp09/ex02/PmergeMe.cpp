#include "PmergeMe.hpp"

void PmergeMe::add(char *val)
{
    int i = -1;
    while (val[++i])
    {
        if (!(val[i] >= '0' && val[i] <= '9'))
        {
            std::cout << "fj";
            throw InputIsWrong();
        }
    }
    std::stringstream ss;
    unsigned int ui;
    ss << val;
    ss >> ui;
    v.push_back(ui);
    l.push_back(ui);
}

void devide(std::vector<unsigned int> &v, int level)
{
    std::vector<unsigned int>::iterator mc = v.begin();
    std::vector<unsigned int>::iterator sc = mc;
    std::advance(sc, level);
    while (sc != v.end())
    {
        if (std::distance(mc ,v.end()) < level * 2)
            break;
        if (*sc > *mc)
        {
            int temp = level;
            while (temp-- && sc != v.end())
            {
                std::swap(*mc, *sc);
                mc++;
                sc++;
            }
        }
        else
        {
            int temp = level;
            while (temp-- && sc != v.end())
            {
                mc++;
                sc++;
            }
        }
        int temp = level;
        while (temp-- && sc != v.end())
        {
            mc++;
            sc++;
        }
    }
}

// void insert(std::vector<unsigned int> &v, int level)
// {
//     int 
// }

void printv(std::vector<unsigned int> &v)
{
    std::string out = "now : ";
    for (std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::stringstream ss;
        ss << *it;
        out += ss.str();
        out += " ";
    }
    std::cout << out << std::endl;
}

void fj(std::vector<unsigned int> &v, int level)
{
    unsigned long check = level * 2;
    if (check > v.size())
        return ;
    devide(v, level);
    printv(v);
    // insert(v, level);
    fj(v, level * 2);
}

void PmergeMe::sort()
{
    std::string out = "Before : ";
    for (std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::stringstream ss;
        ss << *it;
        out += ss.str();
        out += " ";
    }
    std::cout << out << std::endl;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    //fj()
    fj(v, 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);

    clock_gettime(CLOCK_MONOTONIC, &start);

    //fj()

    clock_gettime(CLOCK_MONOTONIC, &end);

    // 경과 시간 계산
    double elapsed2 = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);

    out = "After  : ";
    for (std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::stringstream ss;
        ss << *it;
        out += ss.str();
        out += " ";
    }
    std::cout << out << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::vector : " << elapsed / 1e3 << "us" << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::list   : " << elapsed2 / 1e6 << "ms" << std::endl;
}
