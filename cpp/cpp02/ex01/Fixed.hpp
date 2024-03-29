#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int rawbits;
        static const int fractionalbit = 8;
    public:
        Fixed();
        Fixed(Fixed const &f);
        Fixed(const int val);
        Fixed(const float val);
        Fixed& operator=(Fixed const &f);
        float operator<<(Fixed f);
        ~Fixed();
        int     toInt( void ) const;
        float   toFloat( void ) const;
        int     getRawBits(void);
        void    setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &out, const Fixed &ref);

#endif
