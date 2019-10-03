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
	struct node
	{

		string * array;
		node * next;

	};
	int count;
	node * head;
	int length;
public:
	Stack(int size); //constructor
	//declare functions here
	//Stack data(int length);
	void printAll();
	void push(string topush);
	bool pop(string & data);
	bool top(/*string & data*/); //check if we wil need to pass by reference a string with the professor
	void destroy();
};






#endif /* STACK_HPP_ */
