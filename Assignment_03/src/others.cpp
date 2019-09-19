/*
 * others.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: shahafdan
 */
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


int fact(int value) //returns the factorial of the given number
{
	if (value >= 1)
	{
		return value * fact(value-1);
	}
	else
	{
		return 1;
	}
}

int fib(int value)
{
	//returns the valueth number in the fibbonacci sequence
	//code taken from class
	if(value == 1)
	{
		return 0;
	}
	else if(value == 2)
	{
		return 1;

	}
	else
	{
		return fib(value - 1) + fib(value - 2);
	}
	return 0;
}

void prime (int value)
{
	// print value prime numbers
	//build primeHelper

}

int mult(int a, int b)
{

	return 0;
}

string reverseString(string value)
{

	// reverse the parameter string

	return "";
}

int countOccurrences(string a, string b)
{


	return 0;
}

