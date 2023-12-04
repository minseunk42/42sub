#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->rawbits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    this->rawbits = val << 8;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
    this->rawbits = ((int)val << 8) + (int)(val - roundf(val));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed &Fixed::operator=(Fixed const &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawbits = f.rawbits;
    return *this;
}

float Fixed::operator<<(Fixed f)
{
    return f.toFloat();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits(void)
{ 
    std::cout << "getRawBits member function called" << std::endl;
    return this->rawbits;
}
void    Fixed::setRawBits(int const raw){ this->rawbits = raw;}

int     Fixed::toInt( void ) const
{
    return (this->rawbits >> 8);
}

float   Fixed::toFloat( void ) const
{
    return (roundf(this->rawbits >> 8));
}

