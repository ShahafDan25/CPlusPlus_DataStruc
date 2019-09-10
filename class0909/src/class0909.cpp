//============================================================================
// Name        : class0909.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Circle.hpp"
int main()
{
	Circle c;
	//c.radius = 14;
	// needs to be reffered to the object's member.
	// for example, we want to access the radius of the c object.
	//but radius is private, so line 16 won't work, let comment it out

	//we can get around this problem by building getters and setters.
	c.setRadius(14); //works!
	float f;
	c.calcArea();
	f = c.getArea();
	cout << "area is" << f << endl;
	Circle * p;
	p = new Circle; //last tow lines dynamically allocate into the memory the new Circle
	p -> setRadius(12.0); //call a function of an object that has been dynmically allocate.
	//p is simply a pointer to a Circle object

	return 0;
}
