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
//#include <cstdlib>

Q::Q(int size)
{
	items = new t[size];
	length = size;
	front = 0;
	tail = 0;
}
void Q::insertQ(t * tr)
{
	//the queue is full, we cannot add any more items
			//therefore we will throw an exception
	if((tail == front - 1) || (front == 0 && tail == length - 1))
	{
		throw "Queue is full";
		return;
	}
	items[tail] = tr;
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
bool Q::checkForTrans()
{
	if (tail == front) return false;
	else return true;
}
bool Q::checkProb (int prob) //make a QUEUE function
{
	//generate a random number
	//check for validity
	int r = rand() % 100 + 1;
	if(r <= prob) return true;
	else return false;
}

