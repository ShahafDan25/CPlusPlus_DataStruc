/*
 * Stack.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: shahafdan
 */


#include "Stack.hpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <set>
using namespace std;

//constructor
Stack::Stack()
{
	head = new node;
	length = 0;
	head -> array = new string[length];
	count = 0;
}

Stack Stack::data(int length)
{
	Stack * s = new Stack;
	return * s;

}


bool Stack::pop (string & data)
{
	return false;
}

void Stack::push(string topush)
{
	node * temp = new node;
	temp = head;
	while(temp -> next != nullptr)
	{
		temp = temp -> next;
	}
	//so far we have set the temp node to the most current node;
	//we may have to do this in every function
	if (count == length)
	{
		node * newNode = new node;
		newNode -> next = nullptr;
		count = 0;
		newNode -> array = new string[length];
		temp -> next = newNode;
		temp = temp -> next;
		temp -> array[count] = topush;
	}
	else
	{
		temp -> array[count] = topush;
	}
	count ++; //increase followed index

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

