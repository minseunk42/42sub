#include <iostream>
#include <list>
using namespace std;
int main(void)
{
    string input, cmd;
    char c;
    int N;
    cin >> input >> N;
    list<char> lst;
    for (int i = 0; i < input.length(); ++i) lst.push_back(input[i]);
    list<char>::iterator it = lst.end();
    for (int i = 0; i < N; ++i)
    {
        cin >> cmd;
        if (cmd == "P")
        {
            cin >> c;
            lst.insert(it ,c);
        }
        if (cmd == "L" && it != lst.begin())
            it--;
        if (cmd == "D" && it != lst.end())
            it++;
        if (cmd == "B" && it != lst.begin())
        {
            it--;
            it = lst.erase(it);
        }
    }
    for (list<char>::iterator it = lst.begin(); it != lst.end(); it++)
        cout << *it;
}