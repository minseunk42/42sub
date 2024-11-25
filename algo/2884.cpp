#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int h, m;
    cin >> h >> m;
    int pm;
    pm = m - 45;
    if (pm < 0)
    {
        pm += 60;
        h - 1;
    }
    if (h == 24)
        h = 0;
    cout << h << ' ' << m;

    return 0;
}
