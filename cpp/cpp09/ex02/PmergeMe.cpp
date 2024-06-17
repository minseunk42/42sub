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

void extractSc(std::list<unsigned int> &mc, std::list<unsigned int> &sc, int span)
{
    std::list<unsigned int>::iterator sci = mc.begin();
    std::advance(sci, span);
    std::list<unsigned int>::iterator next;
    while (1)
    {
        next = sci;
        std::advance(next, span);
        sc.insert(sc.end(), sci, next);
        mc.erase(sci, next);
        sci = next;
        if (std::distance(sci, mc.end()) < span * 2)
            break;
        std::advance(sci, span);
    }
    sci = next;
    if (std::distance(sci, mc.end()) >= span)
    {
        std::list<unsigned int>::iterator next = sci;
        std::advance(next, span);
        sc.insert(sc.end(), sci, next);
        mc.erase(sci, next);
    }
}

std::list<unsigned int>::iterator getPos(std::list<unsigned int> &mc, int elecnt, unsigned int val, int span)
{
    std::list<unsigned int> temp;
    std::list<unsigned int>::iterator it = mc.begin();
    for (int i = 0; i < elecnt; ++i)
    {
        temp.push_back(*it);
        std::advance(it, span);
    }
    std::list<unsigned int>::iterator pos = std::lower_bound(temp.begin(), temp.end(), val);
    std::list<unsigned int>::iterator out = mc.begin();
    int idx = std::distance(pos, temp.begin());
    std::advance(out, idx * span);
    return (out);
}

void insertsc(std::list<unsigned int> &mc, int span)
{
    std::list<unsigned int> sc;
    extractSc(mc,sc,span);
    //야곱스탈 수열 만들기
    int cnt = sc.size() / span;
    int js[32];
    js[0] = 1;
    for (int i = 1; i <= 31; ++i)
        js[i] = (0b10 << i) - js[i - 1];
    //초항은 무조건 작을수 밖에 없음
    std::list<unsigned int>::iterator temp = sc.begin();
    std::advance(temp, span);
    mc.insert(mc.begin(), sc.begin() , temp);
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
            std::list<unsigned int>::iterator st = sc.begin();
            std::advance(st, j * span);
            std::list<unsigned int>::iterator ed = st;
            std::advance(ed, span);
            std::list<unsigned int>::iterator pos = getPos(mc, elecnt, *st, span);
            mc.insert(pos, st, ed);
        }
    }
    for (int j = cnt - 1; j >= js[i - 1]; --j)
    {
        elecnt = mc.size() / span;
        std::list<unsigned int>::iterator st = sc.begin();
        std::advance(st, j * span);
        std::list<unsigned int>::iterator ed = st;
        std::advance(ed, span);
        std::list<unsigned int>::iterator pos = getPos(mc, elecnt, *st, span);
        mc.insert(pos, st, ed);
    }
}

void divide(std::list<unsigned int> &v, int span)
{
    std::list<unsigned int>::iterator mc = v.begin();
    std::list<unsigned int>::iterator sc = mc;
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

void fj(std::list<unsigned int> &v, int span)
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
    // fj(v, 1);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    fj(l, 1);
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
    std::cout << "Time to process a range of 3000 elements with std::vector : " << elapsed / 1e6 << "ms" << std::endl;
    std::cout << "Time to process a range of 3000 elements with std::list   : " << elapsed2 / 1e6 << "ms" << std::endl;
}
