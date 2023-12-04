#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int rawbits;
        static const int fractionalbit;
    public:
        Fixed();
        Fixed(Fixed &f);
        Fixed& operator=(Fixed &f);
        ~Fixed();
        int     getRawBits(void);
        void    setRawBits(int const raw);
};

#endif
