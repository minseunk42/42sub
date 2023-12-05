#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
        ~Fixed();
        Fixed&      operator=(Fixed const &fxp);
        bool	    operator>(const Fixed &fxp) const;
	    bool	    operator<(const Fixed &fxp) const;
	    bool	    operator>=(const Fixed &fxp) const;
	    bool	    operator<=(const Fixed &fxp) const;
	    bool	    operator==(const Fixed &fxp) const;
	    bool	    operator!=(const Fixed &fxp) const;
	    Fixed	    operator+(const Fixed &fxp) const;
	    Fixed	    operator-(const Fixed &fxp) const;
	    Fixed	    operator*(const Fixed &fxp) const;
	    Fixed	    operator/(const Fixed &fxp) const;
        Fixed		&operator++(void);
	    Fixed		&operator--(void);
	    const Fixed	operator++(int);
	    const Fixed	operator--(int);
        int     toInt( void ) const;
        float   toFloat( void ) const;
        int     getRawBits(void);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        static Fixed   &min(Fixed &a, Fixed &b);
        static Fixed   const &min(const Fixed &a, const Fixed &b);
        static Fixed   &max(Fixed &a, Fixed &b);
        static Fixed   const &max(const Fixed &a, const Fixed &b);
};

std::ostream    &operator<<(std::ostream &out, const Fixed &fxp);

#endif
