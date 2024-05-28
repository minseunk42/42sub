#include "RPN.hpp"

void RPN::cal(char *input)
{
    double left, right;
    int i = -1;
    while (input[++i])
    {
        if (i % 2 == 1 && input[i] != ' ')
            throw InputIsWrong();
        switch (input[i]) 
        {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            {
                st.push(input[i] - '0');
                break;
            }
            case '+':
            {
                if (st.size() < 2)
                    throw InputIsWrong();
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left + right);
                break;
            }
            case '-':
            {
                if (st.size() < 2)
                    throw InputIsWrong();
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left - right);
                break;
            }
            case '*':
            {
                if (st.size() < 2)
                    throw InputIsWrong();
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left * right);
                break;
            }
            case '/':
            {
                if (st.size() < 2)
                    throw InputIsWrong();
                right = st.top();
                if (right == 0)
                    throw DevideByZero();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left / right);
                break;
            }
            case ' ':
                break;
            default:
                throw InputIsWrong();
        }
    }
    if (st.size() != 1)
        throw InputIsWrong();
    std::cout << st.top();
}
