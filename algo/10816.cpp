#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t1, t2;
    int *arr = new int[20000000];
    cin >> t1;
    int i = 0;
    while (i < t1)
    {
        int temp;
        cin >> temp; 
        if (temp < 0)
            temp = temp * -1 + 10000000;
        arr[temp] += 1;
        i++;
    }
    i = 0;
    cin >> t2;
    while (i < t2)
    {
        int temp;
        cin >> temp; 
        if (temp < 0)
            temp = temp * -1 + 10000000;
        cout << arr[temp] << ' ';
        i++;
    }
    cout << '\n';
}
