#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        int s;
        T *t;
    public:
        Array();
        Array(int s);
        Array(Array const &ref);
        Array&  operator=(Array const &ref);
        T& operator[](int i);
        T& operator[](int i) const;
        ~Array();
    public:
        int size() const;
    public:
        class IndexOutOfRangeException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Index is out of bounds";
            }
        };
};

#endif