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

//Stack Stack::data(int length) //NEEDED
//{
//	Stack * s = new Stack;
//	return * s;
//
//}
void Stack::printAll()
{
	node * temp = new node;
	temp = head;
	int x = 0; //x for index
	while(temp)
	{
		x = 0;
		for(int i = 0; i < count; i++)
		{
			cout << temp -> array [x] << "\t";
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
		// 1. we need to create a new node, and make sure temp is at the right location
		node * newNode = new node;
		newNode -> next = nullptr;
		count = 0;
		newNode -> array = new string[length];
		temp -> next = newNode;
		temp = temp -> next;
		//2. check if it got here
		cout <<"got all the way here" << endl;
		for(int i = count; i > 1 ; i--)
		{
			temp -> array[i] = temp -> array [i-1];
		}
		temp -> array[0] = topush;
	}
	else
	{
		for(int i = count; i > 1 ; i--)
		{
			temp -> array[i] = temp -> array [i-1];
		}
		temp -> array[0] = topush;
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

void Stack::destroy()
{
 //do I need to delete all memory allocated to the arrays inside the nodes as well??
	node * temp = new node;
	while(head) //deleting every node will delete all memory allocated in that node
	{
		temp = head;
		head = head -> next;
		delete temp;
	}
	return;
}




