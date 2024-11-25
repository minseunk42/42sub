#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<string, bool> mp;
    string name, type;
    while (n--)
    {
        cin >> name >> type;
        if (type == "leave")
        {
            mp.erase(name);
        }
        else
        {
            mp[name] = true; 
        }
    }

    for (auto it = mp.rbegin(); it != mp.rend(); ++it)
    {
        if (it->second)
        {
            cout << it->first << "\n";
        }
    }

    return 0;
}
