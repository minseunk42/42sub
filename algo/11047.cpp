#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, goal;
    cin >> n >> goal;
    int arr[11];
    while (n--)
        cin >> arr[n];
    int ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (arr[i] <= goal && arr[i] !=0)
        {
            ans += goal / arr[i];
            goal = goal % arr[i];
        }
    }
    cout << ans;
}
