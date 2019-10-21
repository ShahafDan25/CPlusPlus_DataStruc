/*
 * Q.cpp
 *
 *  Created on: Oct 20, 2019
 *      Author: shahafdan
 */
#include "Q.hpp"
using namespace std;
#include <string>
#include <set>
#include <iostream>
#include <iomanip>

Q::Q(int size)
{
	elems = new trans[size];
	length = size;
}

