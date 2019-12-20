/*
 * Circle.cpp
 *
 *  Created on: Sep 9, 2019
 *      Author: shahafdan
 */


#include "Circle.hpp"
using namespace std;
#include <iostream>
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
Circle::~Circle()
{
	cout << "in destruction" << endl;
}
Circle::Circle() //default constructor to initialize private variables
{
	radius = 0;

	cout << "in construction" << endl;
}

