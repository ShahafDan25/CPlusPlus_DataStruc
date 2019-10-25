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
	length = size;
	tail = 0;
	front = 0;
	items = new t[size];
}
void Q::insertQ(string i, int u)
{
	cout << "Adding Transaction" << endl;
	//first create a new trasaction to add
	t * tr = new t;
	tr -> id = i;
	tr -> units = u;
	//the queue is full, we cannot add any more items
	//therefore we will throw an exception
	if((tail == front - 1) || (front == 0 && tail == length - 1))
	{
		throw "Queue is full";
		return;
	}
	items[tail] = *tr; //ADDING THE FRICKING * IN FRONT OF IT?? SERIOUSLY??
	if(tail == length - 1) tail = 0;
	else tail++;

}
void Q::deleteQ()
{
	cout << "Deleting transaction" << endl;
	if(tail == front)
	{
		throw "Queue is empty";
		return;
	}
	//items[front] = nullptr; //set the first item to null, move to the next item
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
	//srand(time(0));
	int r = rand() % 100 + 1;
	cout << r << " \t < " << prob << endl;
	if(r <= prob) return true;
	else return false;
}

void Q::displayQ()
{
	for(int i = 0; i < length; i++)
	{
		cout << items[i].id << " ";
	}
	cout << endl;
	return;
}
