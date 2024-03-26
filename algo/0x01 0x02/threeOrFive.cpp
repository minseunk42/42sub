#include <iostream>
using namespace std;

unsigned long func(int n)
{
    int N;
    unsigned long out;
    N = n / 3;
    out += 3 * ((N * N + N) / 2);
    N = n / 5;
    out += 5 * ((N * N + N) / 2);
    N = n / 15;
    out -= 15 * ((N * N + N) / 2);
    return (out);
}

int main()
{
    int n;
    cin >> n;
    cout << func(n) << '\n';
}