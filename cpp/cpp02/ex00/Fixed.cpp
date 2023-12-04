#include "Fixed.hpp"

Fixed::Fixed()
{
    this->rawbits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed &Fixed::operator=(Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->rawbits = f.getRawBits();
    return *this;
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