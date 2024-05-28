#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <exception>

class RPN
{
    private:
        RPN(RPN const &ref){(void)ref;};
        RPN&  operator=(RPN const &ref){(void)ref; return *this;};
        std::stack<double> st;
    public:
        RPN(){};
        ~RPN(){};
        void cal(char *av);
    public:
        class DevideByZero : public std::exception 
        {
            virtual const char* what() const throw()
            {
                return "Error: Devide By Zero";
            }
        };
        class InputIsWrong : public std::exception 
        {
            virtual const char* what() const throw()
            {
                return "Error: Input Is Wrong";
            }
        };
};

#endif