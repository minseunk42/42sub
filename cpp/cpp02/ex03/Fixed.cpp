#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->rawbits = 0;
}

Fixed::Fixed(const int val)
{
    this->rawbits = val << this->fractionalbit;
}

Fixed::Fixed(const float val)
{
    this->rawbits = roundf(val * (1 << this->fractionalbit));
}

Fixed::Fixed(Fixed const &f)
{
    *this = f;
}

Fixed::~Fixed(){}

Fixed &Fixed::operator=(Fixed const &f)
{
    this->rawbits = f.rawbits;
    return *this;
}

std::ostream    &operator<<(std::ostream &out, const Fixed &ref)
{
    out << ref.toFloat();
	return (out);
}

bool	    Fixed::operator>(const Fixed &ref) const
{
    return (this->rawbits > ref.rawbits);
}

bool	    Fixed::operator<(const Fixed &ref) const
{
    return (this->rawbits < ref.rawbits);
}

bool	    Fixed::operator>=(const Fixed &ref) const
{
    return (this->rawbits >= ref.rawbits);
}

bool	    Fixed::operator<=(const Fixed &ref) const
{
    return (this->rawbits <= ref.rawbits);
}

bool	    Fixed::operator==(const Fixed &ref) const
{
    return (this->rawbits == ref.rawbits);
}

bool	    Fixed::operator!=(const Fixed &ref) const
{
    return (this->rawbits != ref.rawbits);
}

Fixed	    Fixed::operator+(const Fixed &ref) const
{
    return Fixed((float)(this->rawbits + ref.rawbits) / (1 << this->fractionalbit));
}

Fixed	    Fixed::operator-(const Fixed &ref) const
{
   return Fixed((float)(this->rawbits - ref.rawbits) / (1 << this->fractionalbit));
}

Fixed	    Fixed::operator*(const Fixed &ref) const
{
    double temp = (double)(this->rawbits * ref.rawbits);
    temp /= (1 << this->fractionalbit * 2);
    return Fixed((float)temp);
}

Fixed	    Fixed::operator/(const Fixed &ref) const
{
    double temp = (double)((this->rawbits * 256) / ref.rawbits);
    temp /= (1 << this->fractionalbit);
    return Fixed((float)temp);
}

Fixed		&Fixed::operator++(void)
{
    this->rawbits += 1;
    return *this;
}

Fixed		&Fixed::operator--(void)
{
    this->rawbits -= 1;
    return *this;
}

const Fixed	Fixed::operator++(int)
{
    const Fixed temp = Fixed((float)this->rawbits / (1 << this->fractionalbit));
    this->rawbits += 1;
    return temp;
}

const Fixed	Fixed::operator--(int)
{
    const Fixed temp = Fixed((float)this->rawbits / (1 << this->fractionalbit));
    this->rawbits -= 1;
    return temp;
}

int     Fixed::getRawBits(void)
{ 
    return this->rawbits;
}

int     Fixed::getRawBits(void) const
{ 
    return this->rawbits;
}

void    Fixed::setRawBits(int const raw){ this->rawbits = raw;}

int     Fixed::toInt( void ) const
{
    return (this->rawbits >> this->fractionalbit);
}

float   Fixed::toFloat( void ) const
{
    return ((float)this->rawbits / (1 << this->fractionalbit));
}

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    return (a > b ? b : a);
}

Fixed   const &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a.getRawBits() > b.getRawBits() ? b : a;
}

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

Fixed   const &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
