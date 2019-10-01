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
using namespace std;


class Stack
{
private:
	struct node
	{

		int data [];
		node * next;
	};

	node * llh;
	int count;
public:
	//declare functions here
	int getCount();
	void incCount();

};






#endif /* STACK_HPP_ */
