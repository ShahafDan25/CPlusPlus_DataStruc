/*
 * Stack.cpp
 *
 *  Created on: Sep 30, 2019
 *      Author: shahafdan
 */


#include "Stack.hpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <set>
using namespace std;


Stack Stack::data(int length)
{
	Stack * s = new Stack;
	return * s;

}
int Stack::getCount()
{
	return count;
}

void Stack::incCount()
{
	count++;
}

bool Stack::pop (string & data)
{
	return false;
}

void Stack::push(string topush)
{
	if(count == 0)
	{
		if(!head)
		{
			head = new node;
			head-> next = nullptr;
			head -> data = new string[length];
		}
		else
		{
			node newNode = new node;
			newNode -> next = nullptr;
			newNode ->

		}
		data = new string[10]; //change later
	}
	else if(count == 10)
	{
		count = 0;
		push(topush);
	}
	else
	{
		data[count] = topush;
		count++;
	}
	return;
}

bool Stack::top (string & data)
{
	return false;
}

void destroy()
{
	return;
}




