/*
 * Circle.hpp
 *
 *  Created on: Sep 9, 2019
 *      Author: shahafdan
 */

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

using namespace std;

class Circle
{

private:
	float radius;
	float area;

public:
	void calcArea();
	void setRadius(float);
	float getArea();
};



#endif /* CIRCLE_HPP_ */
