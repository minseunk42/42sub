#include <iostream>

using namespace std;

int get_cnt(int is, int js, string *arr, int cnt, char togle)
{
    int temp = 0;
    for (int i = is; i < is + 8; ++i)
    {
        for (int j = js; j < js + 8; ++j)
        {
            if (arr[i][j] == togle)
                temp++;
            if (temp > cnt)
                return temp;
            if (j == js + 7)
                break ;
            if (togle == 'B')
                togle = 'W';
            else
                togle = 'B'; 
        }
    }
    return temp;
}

int main(void)
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int cnt;
    int temp;
    int r,c;
    cin >> r >> c;
    string *arr;
	arr = new string[r];
	for (int i = 0; i < r; i++) {
        cin >> arr[i];
	}
    cnt = 999999;
    for (int i = 0; i < r - 7; i++)
    {   
        for (int j = 0; j < c - 7; j++)
        {
            temp = get_cnt(i, j, arr, cnt, 'B');
            cnt = cnt < temp ? cnt : temp;
            temp = get_cnt(i, j, arr, cnt, 'W');
            cnt = cnt < temp ? cnt : temp;
        }
    }
    cout << cnt << '\n';
    delete[] arr;
    return 0;
}
