/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:04:06 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/13 13:09:09 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int FixedPoint;
    static const int Fraction = 8;

public:
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed(const int i);
    Fixed(const float f);
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits( void ) const;
    void    setRawBits( int const raw );
    Fixed &operator=(const Fixed &other);
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    static const Fixed &min(const Fixed &a,const Fixed &b);
    static Fixed &min(Fixed &a,Fixed &b);
    static const  Fixed &max(const Fixed &a,const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    ~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif