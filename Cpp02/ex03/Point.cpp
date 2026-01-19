/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:37:22 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/13 17:53:33 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() :x(Fixed(0)) , y(Fixed(0)) {}

Point::Point(const float x_val, const float y_val) :x(Fixed(x_val)), y(Fixed(y_val)){}
Point::Point(const Point &other) :x(other.x) , y(other.y){}
Point &Point::operator=(const Point &)
{
    return *this;
}

Point::~Point() {}