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
	items = new trans[size];
	length = size;
	front = 0;
	tail = 0;
}
void Q::insertQ(int value)
{
	//the queue is full, we cannot add any more items
			//therefore we will throw an exception
	if(tail == front - 1 || (front == 0 && tail = length - 1))
	{
		throw "Queue is full";
		return;
	}
	items[tail] = value;
	if(tail == length - 1) tail = 0;
	else tail++;

}
void Q::deleteQ()
{
	if(tail == front)
	{
		throw "Queue is empty";
		return;
	}
	items[front] = NULL; //set the first item to null, move to the next item
	if(front == length - 1) front = 0;
	else front++;
}

