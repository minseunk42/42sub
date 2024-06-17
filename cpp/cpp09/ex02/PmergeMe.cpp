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

int powerTwo(int n)
{
    int out = 1;
    while (n--)
        out *= 2;
    return out;
}

void extractSc(std::vector<unsigned int> &mc, std::vector<unsigned int> &sc, int span)
{
    std::vector<unsigned int>::iterator sci = mc.begin();
    std::advance(sci, span);
    while (1)
    {
        sc.insert(sc.end(), sci, sci + span);
        mc.erase(sci, sci + span);
        if (std::distance(sci, mc.end()) < span * 2)
            break;
        std::advance(sci, span);
    }
    if (std::distance(sci, mc.end()) >= span)
    {
        sc.insert(sc.end(), sci, sci + span);
        mc.erase(sci, sci + span);
    }
}

std::vector<unsigned int>::iterator getPos(std::vector<unsigned int> &mc, int elecnt, unsigned int val, int span)
{
    std::vector<unsigned int> temp;
    std::vector<unsigned int>::iterator it = mc.begin();
    for (int i = 0; i < elecnt; ++i)
    {
        temp.push_back(*it);
        std::advance(it, span);
    }
    std::vector<unsigned int>::iterator pos = std::lower_bound(temp.begin(), temp.end(), val);
    int idx = pos - temp.begin();
    return (mc.begin() + (idx * span));
}

void insertsc(std::vector<unsigned int> &mc, int span)
{
    std::vector<unsigned int> sc;
    extractSc(mc,sc,span);
    //야곱스탈 수열 만들기
    int cnt = sc.size() / span;
    int js[32];
    js[0] = 1;
    for (int i = 1; i <= 31; ++i)
        js[i] = (0b10 << i) - js[i - 1];
    //초항은 무조건 작을수 밖에 없음
    mc.insert(mc.begin(), sc.begin() , sc.begin() + span);
    if (cnt == 1)
        return ;
    //이진탐색하여 삽입
    int elecnt;
    int i = 0;
    while (js[++i] < cnt)
    {
        elecnt = powerTwo(i + 1) - 1;
        for (int j = js[i] - 1; j >= js[i - 1]; --j)
        {
            std::vector<unsigned int>::iterator pos = getPos(mc, elecnt, *(sc.begin() + (j * span)), span);
            mc.insert(pos, sc.begin() + (j * span), sc.begin() + (j * span) + span);
        }
    }
    for (int j = cnt - 1; j >= js[i - 1]; --j)
    {
        elecnt = mc.size() / span;
        std::vector<unsigned int>::iterator pos = getPos(mc, elecnt, *(sc.begin() + (j * span)), span);
        mc.insert(pos, sc.begin() + (j * span), sc.begin() + (j * span) + span);
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
    fj(v, 1);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    // fj(l, 1);
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
    std::cout << "Time to process a range of 3000 elements with std::vector : " << elapsed / 1e6 << "ms" << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::vector   : " << elapsed2 / 1e6 << "ms" << std::endl;
}
