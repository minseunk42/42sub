#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string temp;
    while (42)
    {
        getline(cin, temp);
        if (temp == "") break;
        cout << temp << "\n";
    }
}
