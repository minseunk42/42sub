#include <iostream>
using namespace std;

int func(int arr[], int n)
{
    char a[101] = {0,};
    for (int i = 0; i < n; ++i)
    {
        if (a[arr[i]])
            return (1);
        a[100 -arr[i]] = 1;
    }
    return (0);
}

int main()
{
    int arr[5] = {4,12,95,87};

    cout << func(arr,4) << '\n';
}