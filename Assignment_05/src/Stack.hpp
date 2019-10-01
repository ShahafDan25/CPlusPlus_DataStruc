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

		string * data;
		node * next;
	};

	node * head;
	int length;
	int count;
public:
	//declare functions here
	Stack data(int length);
	int getCount();
	void incCount();
	void push(string topush);
	bool pop(string & data);
	bool top(string & data);
	void destroy();
};






#endif /* STACK_HPP_ */
