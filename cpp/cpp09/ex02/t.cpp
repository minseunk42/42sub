#include "PmergeMe.hpp"
void extractSc(std::list<unsigned int> &mc, std::list<unsigned int> &sc, int span)
{
    std::list<unsigned int>::iterator sci = mc.begin();
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
    int idx = pos - temp.begin();
    return (mc.begin() + (idx * span));
}

void insertsc(std::list<unsigned int> &mc, int span)
{
    std::list<unsigned int> sc;
    // std::cout << "mc";printv(mc);
    extractSc(mc,sc,span);
    // std::cout << "sc";printv(sc);
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
            std::list<unsigned int>::iterator pos = getPos(mc, elecnt, *(sc.begin() + (j * span)), span);
            mc.insert(pos, sc.begin() + (j * span), sc.begin() + (j * span) + span);
        }
    }
    for (int j = cnt - 1; j >= js[i - 1]; --j)
    {
        elecnt = mc.size() / span;
        std::list<unsigned int>::iterator pos = getPos(mc, elecnt, *(sc.begin() + (j * span)), span);
        mc.insert(pos, sc.begin() + (j * span), sc.begin() + (j * span) + span);
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


