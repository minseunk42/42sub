#include "PmergeMe.hpp"

void PmergeMe::add(char *val)
{
    int i = -1;
    while (val[++i])
    {
        if (!(val[i] > '0' && val[i] < '9'))
            throw InputIsWrong();
    }
    std::stringstream ss;
    unsigned int ui;
    ss << val;
    ss >> ui;
    v.push_back(ui);
    l.push_back(ui);
}

void fj(std::vector<unsigned int> &v, int level)
{
    std::vector<unsigned int>::iterator mc = v.begin();
    std::vector<unsigned int>::iterator sc = mc;
    std::advance(sc, level);


}

void PmergeMe::sort()
{
    std::string out = "Before : ";
    for (std::vector<unsigned int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
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
    for (std::list<unsigned int>::iterator it = l.begin(); it != l.end(); ++it)
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
