#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    int arr[10] = {0,};
    while (n)
    {
        arr[n % 10]++;
        n /= 10;
    }
    arr[6] += arr[9];
    if (arr[6] % 2 == 0)
        arr[6] /= 2;
    else
        arr[6] = arr[6] / 2 + 1;
    int max = 0;
    for (int i = 0; i < 9; ++i)
        max = arr[i] > max ? arr[i] : max;
    cout << max;
    return 0;
}
