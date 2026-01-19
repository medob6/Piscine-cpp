/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:04:06 by mbousset          #+#    #+#             */
/*   Updated: 2025/11/19 15:12:14 by mbousset         ###   ########.fr       */
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
    Fixed &operator=(const Fixed &other);
    int getRawBits( void ) const;
    void    setRawBits( int const raw );
    ~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif