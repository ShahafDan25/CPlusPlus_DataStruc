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

bool pop (string & data)
{
	return false;
}

void push(string topush)
{
	return;
}

bool top (string & data)
{
	return false;
}

void destroy()
{
	return;
}




