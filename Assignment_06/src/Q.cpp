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
	cout << "Transaction Added!" << endl;
	//first create a new trasaction to add
	t * tr = new t;
	tr -> id = i;
	tr -> units = u;
	//the queue is full, we cannot add any more items
	//therefore we will throw an exception
	if(tail == front - 1)
	{
		cout << "Q IS FULL, cannot add any more transactions. THROWING EXCEPTION:" << endl;
		throw "Queue is full";
		return;
	}
	else if(front ==0 && tail == length - 1)
	{
		cout << "Q IS FULL, cannot add any more transactions. THROWING EXCEPTION:" << endl;
		throw "Queue is full";
		return;
	}
	items[tail] = *tr; //ADDING THE FRICKING * IN FRONT OF IT?? SERIOUSLY??
	if(tail == length - 1) tail = 0;
	else tail++;

}
void Q::deleteQ()
{
	t * tr = new t;
	tr -> id = "";
	tr -> units = 0;

	cout << "Deleting transaction! Because: ";
	if(tail == front)
	{
		cout << "Q IS EMPTY, cannot delete anything. THROWING EXCEPTION:" << endl;
		throw "Queue is empty";
		return;
	}
	else
	{
		//tr = nullptr;
		items[front] = *tr;
	}
	//items[front] = nullptr; //set the first item to null, move to the next item
	if(front == length - 1) front = 0;
	else front++;
	return;
}
bool Q::checkForTrans()
{
	if (tail == front) return false;
	else return true;
}
bool Q::checkProb (int prob, string & stats) //make a QUEUE function
{
	//generate a random number
	//check for validity via generating a random number to check probability
	int r = rand() % 100 + 1;
	//cout << r << " \t < " << prob << endl;
	if(r <= prob)
	{
		stats =  to_string(r) +  "  <  " + to_string(prob) + "\n";
		return true;
	}
	else
	{
		stats = to_string(r) + " not < " + to_string(prob) + "\n";
		return false;
	}
}

void Q::displayQ()
{
	bool displayed = false;
	for(int i = 0; i < length; i++)
	{
		displayed = true;
		if(items[i].id != "") cout << items[i].id << " ";
	}
	if(!displayed) cout << " CURRENTLY EMPTY ";
	cout << endl;
	return;
}
