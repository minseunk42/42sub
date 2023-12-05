#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->rawbits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    this->rawbits = val << this->fractionalbit;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
    this->rawbits = roundf(val * (1 << this->fractionalbit));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawbits = f.rawbits;
    return *this;
}

std::ostream    &operator<<(std::ostream &out, const Fixed &ref)
{
    out << ref.toFloat();
	return (out);
}

int     Fixed::getRawBits(void)
{ 
    std::cout << "getRawBits member function called" << std::endl;
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
