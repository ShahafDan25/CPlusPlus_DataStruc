/*
 * Stack.hpp
 *
 *  Created on: Sep 30, 2019
 *      Author: shahafdan
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <string>
#include <iomanip>
#include <set>
#include <iostream>
using namespace std;


class Stack
{
private:
	//equivalent to linked list definition
	struct node
	{

		string * array;
		node * next;

	};
	node * head;

	int count; //equivalent to topElement
	int length; //equivalent to array size
public:
	Stack(int size); //constructor
	//declare functions here
	int getCount();
	void printAll();
	void push(string topush);
	bool pop(string & data);
	bool top(string & data); //check if we wil need to pass by reference a string with the professor
	void destroy();
	void destroyAll();
};






#endif /* STACK_HPP_ */
