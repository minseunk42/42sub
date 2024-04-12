#include <iostream>
using namespace std;

bool isPd(string in)
{
    int i = 0;
    int ri = in.size() - 1;
    while (i < ri)
    {
        if (in[i++] != in[ri--])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string in;
    cin >> in;
    while (in != "0")
    {
        if (isPd(in))
            cout << "yes\n";
        else
            cout << "no\n";
        cin >> in;
    }
}