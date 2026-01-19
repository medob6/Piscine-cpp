/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:03:05 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/13 10:37:27 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : FixedPoint(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed &other)
{
    FixedPoint = other.FixedPoint;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other) {
        FixedPoint = other.FixedPoint;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->FixedPoint);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->FixedPoint = raw;
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    FixedPoint = i << Fraction;
}


// so for floats we try to represent it as f / 256  = x * 256 + y / 256 , y < 256 
Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    FixedPoint = roundf(f * (1 << Fraction)); 
}

float Fixed::toFloat(void) const
{
    int integerPart = FixedPoint >> Fraction;
    int fractionalBits = FixedPoint & ((1 << Fraction) - 1);
    float fractionalPart = fractionalBits / (float)(1 << Fraction);
    return integerPart + fractionalPart;
}

int Fixed::toInt( void ) const
{
    return (FixedPoint >> Fraction);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}
