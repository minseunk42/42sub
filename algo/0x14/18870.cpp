#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int origin[1000001];
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> origin[i];
        v.push_back(origin[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n ; ++i)
        cout << lower_bound(v.begin(), v.end(), origin[i]) - v.begin() << ' ';
}
