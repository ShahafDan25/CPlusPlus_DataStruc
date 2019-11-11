/*
 * Heap.cpp
 *
 *  Created on: Nov 10, 2019
 *      Author: shahafdan
 */

#include "Heap.hpp"//include class declaration and definition
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//constructor
Heap::Heap()
{
	root = new node; //dynamically initialize
	levels = 0; //set amount of levels in the tree (floors) to zero
}

void Heap::populateFromArray(int thatArray[])
{
	return;
}


