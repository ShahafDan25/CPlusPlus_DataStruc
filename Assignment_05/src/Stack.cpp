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

//constructor
Stack::Stack(int size)
{
	head = new node;
	length = size;
	head -> array = new string[length];
	count = 0;
}

//Stack Stack::data(int length)
//{
//	Stack * s = new Stack;
//	return * s;
//
//}
void Stack::printAll()
{
	node * temp = new node;
	temp = head;
	int ind = 0;
	while(temp)
	{
		ind = 0;
		for(int i = 0; i < count; i++)
		{
			cout << temp -> array [ind] << "\t";
		}
		temp = temp -> next;
	}
	return;

}

bool Stack::pop (string & data)
{
	node * temp = new node;
	temp = head;
	while(temp)
	{
		temp = temp -> next;
	} //make sure we are at the recent node;
	//if there are zero elements in the array, return false, else print the top element item and return true
	if(count == 0)
	{
		return false;
	}
	else
	{
		for(int i = 0; i < length - 1; i++)
		{
			temp -> array[i] = temp -> array[i+1]; //move up all the elements in the array
		}
		return true;
	}
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

bool Stack::top (/*string & data*/)
{
	node * temp = new node;
	temp = head;
	while(temp)
	{
		temp = temp -> next;
	} //make sure we are at the recent node;

	//if there are zero elements in the array, return false, else print the top element item and return true
	if(count == 0)
	{
		return false;
	}
	else
	{
		cout << "the top element is: \t " <<  temp -> array [0] << endl;
		return true;
	}

}

void destroy()
{
	return;
}




