#include <iostream>

using namespace std;
int marr[2000001];
int arr[1000001] = {};

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,x;
    cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> arr[i];
	}
    cin >> x;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (x- arr[i] && marr[x - arr[i]])
            cnt++;
        marr[arr[i]] = 1;
    }
    cout << cnt;
    return 0;
}
