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
    n /= 2;
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

void extractSc(std::vector<unsigned int> &mcv, std::vector<unsigned int> &scv, int span)
{
    std::vector<unsigned int>::iterator sci = mcv.begin();
    std::advance(sci, span);
    while (1)
    {
        scv.insert(scv.end(), sci, sci + span);
        mcv.erase(sci, sci + span);
        if (std::distance(sci, mcv.end()) < span * 2)
            break;
        std::advance(sci, span);
    }

}

std::vector<unsigned int>::iterator getPos(std::vector<unsigned int> &mcv, int elecnt, unsigned int val, int span)
{
    int mid = elecnt / 2;
    std::vector<unsigned int>::iterator it = mcv.begin() + (mid * span);
    while (mid)
    {
        if (*it == val)
            return it;
        mid /= 2;
        if (*it < val)
            it = it + (mid * span);
        else
            it = it - (mid * span);
    }
    if (*it < val)
        return (it + span);
    else
        return it;
}

void insertsc(std::vector<unsigned int> &mcv, int span)
{
    std::vector<unsigned int> scv;
    std::cout << "mcv";printv(mcv);
    extractSc(mcv,scv,span);
    std::cout << "scv";printv(scv);
    //야곱스탈 수열 만들기
    int n = logTwo(scv.size() / span);
    std::vector<unsigned int> js(n + 1);
    js[0] = 1;
    for (int i = 1; i < n; ++i)
        js[i] = (1 << i) - js[i - 1];
    mcv.insert(mcv.begin(), scv.begin() , scv.begin() + span);
    scv.erase(scv.begin() , scv.begin() + span);
    //이진탐색하여 삽입
    int elecnt;
    for (int i = 1; i < n; ++i)
    {
        elecnt = powerTwo(i + 1) - 1;
        for (int j = js[i] - 1; j >= 0; --j)
        {
            std::vector<unsigned int>::iterator pos = getPos(mcv, elecnt, *(scv.begin() + (j * span)), span);
            mcv.insert(pos, scv.begin() + (j * span), scv.begin() + (j * span) + span);
            scv.erase(scv.begin() + (j * span), scv.begin() + (j * span) + span);
        }
    }
    while (scv.size())
    {
        std::vector<unsigned int>::iterator it = scv.begin();
        //upper_bound는 이미 정렬된거에만 쓸수 있다.
        printv(mcv);
        std::vector<unsigned int>::iterator pos = std::upper_bound(mcv.begin(), mcv.end(), *(it));
        mcv.insert(pos, it, it + span);
        scv.erase(it, it + span);
    }
}

void divide(std::vector<unsigned int> &v, int span)
{
    std::vector<unsigned int>::iterator mc = v.begin();
    std::vector<unsigned int>::iterator sc = mc;
    std::advance(sc, span);
    while (sc != v.end())
    {
        if (std::distance(mc ,v.end()) < span * 2)
            break;
        if (*sc > *mc)
        {
            int temp = span;
            while (temp-- && sc != v.end())
            {
                std::swap(*mc, *sc);
                mc++;
                sc++;
            }
        }
        else
        {
            int temp = span;
            while (temp-- && sc != v.end())
            {
                mc++;
                sc++;
            }
        }
        int temp = span;
        while (temp-- && sc != v.end())
        {
            mc++;
            sc++;
        }
    }
}

void fj(std::vector<unsigned int> &v, int span)
{
    unsigned long check = span * 2;
    if (check > v.size())
        return ;
    divide(v, span);
    fj(v, span * 2);
    insertsc(v, span);
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
