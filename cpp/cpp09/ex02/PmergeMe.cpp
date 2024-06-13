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

int logTwo(int n)
{
    int out = 0;
    while (n)
    {
        n /= 2;
        out++;
    }
    return out;
}

int powerTwo(int n)
{
    int out = 1;
    while (n--)
        out *= 2;
    return out;
}

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

void divideSc(std::vector<unsigned int> &mcv, std::vector<unsigned int> &scv, int level)
{
    std::vector<unsigned int>::iterator sci = mcv.begin();
    std::advance(sci, level);
    while (1)
    {
        scv.insert(scv.end(), sci, sci + level);
        mcv.erase(sci, sci + level);
        if (std::distance(sci, mcv.end()) < level * 2)
            break;
        std::advance(sci, level);
    }
}

void insertsc(std::vector<unsigned int> &mcv, int level)
{
    std::vector<unsigned int> scv;
    divideSc(mcv,scv,level);
    
    //야곱스탈 수열 만들기
    int n = logTwo(scv.size() / level);
    std::vector<unsigned int> js(n);
    js[0] = 1;
    for (int i = 1; i < n; ++i)
        js[i] = (1 << i) - js[i - 1];

    //이진탐색하여 삽입
    for (int i = 0; i < n; ++i)
    {
        int elecnt = powerTwo(i + 1);
        for (int j = js[i] - 1; j >= 0; --j)
        {
            std::vector<unsigned int>::iterator pos = std::upper_bound(mcv.begin(), mcv.begin() + elecnt, *(scv.begin() + j));
            mcv.insert(pos, scv.begin() + j, scv.begin() + j + level);
            scv.erase(scv.begin() + j, scv.begin() + j + level);
        }
    }
    //자투리 삽입부분

}

void divide(std::vector<unsigned int> &v, int level)
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

void fj(std::vector<unsigned int> &v, int level)
{
    unsigned long check = level * 2;
    if (check > v.size())
        return ;
    divide(v, level);
    fj(v, level * 2);
    insertsc(v, level);
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
    std::cout << "Time to process a range of 3000 elements with std::vector : " << elapsed / 1e6 << "us" << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::list   : " << elapsed2 / 1e6 << "ms" << std::endl;
}
