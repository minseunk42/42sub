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
    cnt++;
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

    // 시작 시간 측정
    clock_gettime(CLOCK_MONOTONIC, &start);

    // 측정하고자 하는 작업
    for (int i = 0; i < 100000000; ++i);

    // 끝 시간 측정
    clock_gettime(CLOCK_MONOTONIC, &end);

    // 경과 시간 계산
    double elapsed = ((end.tv_sec - start.tv_sec) / 1e12) + (end.tv_nsec - start.tv_nsec);
    double elapsed2 = (end.tv_nsec - start.tv_nsec);

    out = "After  : ";
    for (std::list<unsigned int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::stringstream ss;
        ss << *it;
        out += ss.str();
        out += " ";
    }
    std::cout << "Time to process a range of 3000 elements with std::vector : " << elapsed / 1000000000 << "us" << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::list   : " << elapsed2 / 1000000 << "us" << std::endl;
}
