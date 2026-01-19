/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:03:05 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/13 15:06:03 by mbousset         ###   ########.fr       */
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
    int integerPart = toInt();
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

bool    Fixed::operator>(const Fixed &other) const
{
    if (this->toFloat() > other.toFloat())
        return (true);
    return (false);
}

bool    Fixed::operator>=(const Fixed &other) const
{
    if (this->toFloat() >= other.toFloat())
        return (true);
    return (false);    
}

bool    Fixed::operator<(const Fixed &other) const
{
    if (this->toFloat() < other.toFloat())
        return (true);
    return (false);    
}

bool    Fixed::operator<=(const Fixed &other) const
{
    if (this->toFloat() <= other.toFloat())
        return (true);
    return (false);    
}

bool    Fixed::operator==(const Fixed &other) const
{
    if (this->toFloat() == other.toFloat())
        return (true);
    return (false);    
}

bool    Fixed::operator!=(const Fixed &other) const
{
    if (this->toFloat() != other.toFloat())
        return (true);
    return (false);    
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.FixedPoint = this->FixedPoint + other.FixedPoint;
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.FixedPoint = (this->FixedPoint - other.FixedPoint);
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    int64_t temp = static_cast<int64_t>(this->FixedPoint) * other.FixedPoint;
    res.FixedPoint = temp >> Fraction;
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed res;
    int64_t temp = (static_cast<int64_t>(this->FixedPoint) << Fraction);
    res.FixedPoint = temp / other.FixedPoint;
    return res;
}

Fixed &Fixed::operator++()
{
    ++FixedPoint;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    ++FixedPoint;
    return (old);
}

Fixed &Fixed::operator--()
{
    --FixedPoint;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    --FixedPoint;
    return (old);
}

const Fixed &Fixed::min(const Fixed &a,const Fixed &b)
{
    if (b <= a)
        return (b);
    return (a);
}

Fixed &Fixed::min(Fixed &a,Fixed &b)
{
    if (b <= a)
        return (b);
    return (a);
}

const  Fixed &Fixed::max(const Fixed &a,const Fixed &b)
{
    if (b >= a)
        return (b);
    return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (b >= a)
        return (b);
    return (a);
}

