/*
 * Stack.hpp
 *
 *  Created on: Oct 2, 2019
 *      Author: shahafdan
 */

#ifndef STACK_HPP_
#define STACK_HPP_
#include <string>
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
	Stack(); //constructor
	//declare functions here
	Stack data(int length);
	void push(string topush);
	bool pop(string & data);
	bool top(string & data);
	void destroy();
};



#endif /* STACK_HPP_ */
