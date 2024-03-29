#include <iostream>
#include <list>
using namespace std;
int main(void)
{
    int n,k;
    cin >> n >> k;
    list<int> lst;
    for (int i = 1; i <= n; ++i) lst.push_back(i);
    list<int>::iterator iter = lst.begin();
    cout << "<";
    int flag = 1;
    while (lst.size())
    {
        for (int i = 0; i < k; ++i)
        {
            iter++;
            if (flag)
            {
                iter--;
                flag = 0;
            }
            if (iter == lst.end())
            {
                iter = lst.begin();
                continue;
            }
        }
        cout << *iter;
        if (lst.size() != 1)
            cout << ", ";
        iter = lst.erase(iter);
        iter--;
    }
    cout << ">";
    return 0;
}