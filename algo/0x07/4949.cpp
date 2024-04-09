#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> st;
    while (1)
    {
        char inputstr[20000] = {0,};
        cin.getline(inputstr, 20000);
        if (inputstr[0] == '.') break;
        int i = 0;
        while (inputstr[i] != '.')
        {
            if (inputstr[i] == '(' || inputstr[i] == '[')
                st.push(inputstr[i]);
            if (inputstr[i] == ')')
            {
                if (st.top() != '(')
                    break;
                else
                    st.pop();
            }
            if (inputstr[i] == ']')
            {
                if (st.top() != '[')
                    break;
                else
                    st.pop();
            }
            i++;
        }
        if (st.empty())
            cout << "yes\n";
        else
        {
            cout << "no\n";
            while(!st.empty())
                st.pop();
        }
    }
}