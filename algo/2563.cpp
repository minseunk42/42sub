#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int arr[100][100] = {0, };
    int t;
    cin >> t;
    int r,c;
    int cnt = 0;
    while (t--)
    {
        cin >> r;
        cin >> c;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (!arr[i + r][j + c])
                {
                    arr[i + r][j + c] = 1;
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
}
