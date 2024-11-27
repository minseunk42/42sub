#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int h, m;
    cin >> h >> m;
    m = m - 45;
    if (m < 0)
    {
        m += 60;
        h = h - 1;
    }
    if (h == -1)
        h = 23;
    cout << h << ' ' << m;

    return 0;
}
