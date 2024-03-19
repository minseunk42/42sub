#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int rm_max = static_cast<int>(round(t * 0.15));
    int rm_min = rm_max;
    int temp;
    int arr[31] = {0,};
    if (t == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    while (t--)
    {        
        cin >> temp;
        arr[temp]++;
    }
    temp = 30;
    while (rm_max--)
    {
        if (arr[temp])
            arr[temp]--;
        else
        {
            while (!arr[temp])
                temp--;
            arr[temp]--;
        }
    }
    temp = 1;
    while (rm_min--)
    {
        if (arr[temp])
            arr[temp]--;
        else
        {
            while (!arr[temp])
                temp++;
            arr[temp]--;
        }
    }
    double sum = 0;
    double cnt = 0;
    for (int i = 1; i < 31; ++i)
    {
        sum += arr[i] * i;
        cnt += arr[i];
    }
    cout << static_cast<int>(round(sum / cnt)) << '\n';
    return 0;
}
