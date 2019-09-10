/*
 * Circle.cpp
 *
 *  Created on: Sep 9, 2019
 *      Author: shahafdan
 */


#include "Circle.hpp"

void Circle::calcArea()
{
	area = radius * 3.14;
}
void Circle::setRadius(float r)
{
	radius = r;
}
float Circle::getArea()
{
	return area;
}

