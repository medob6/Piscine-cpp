/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:36:57 by mbousset          #+#    #+#             */
/*   Updated: 2025/10/17 15:00:51 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float Point::TriangleArea(const Point &a,const Point &b,const Point &c)
{
    float Area;
    
    Area = (a.x - c.x).toFloat() * (b.y - a.y).toFloat();
    Area -= (a.x - b.x).toFloat() * (c.y - a.y).toFloat();
    if (Area < 0)
        Area *= -1;
    return (0.5f * Area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool inside;
    float   Area = Point::TriangleArea(a,b,c);
    float   area1 = Point::TriangleArea(a,b,point);
    float   area2 = Point::TriangleArea(point,b,c);
    float   area3 = Point::TriangleArea(a,point,c);
    if(area1 == 0 || area2 == 0 || area1 == 0)
        return false;
    inside = (Area == (area1 + area2 + area3));
    return (inside);
}
