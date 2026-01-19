/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:37:30 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/13 18:15:15 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const  x;
    Fixed const  y;

public:
    Point(void);
    Point(const float x_val, const float y_val);
    Point(const Point &other);
    Point &operator=(const Point &);
    static float TriangleArea(const Point &a,const Point &b,const Point &c);
    ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif