//============================================================================
// Name        : Assignment_03a.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<algorithm>
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#include <cmath>

//function declarations
int fact(int value);
int fib (int value);
void primeChecker(int number, int value);
void prime(int value);
string reverseString(string s);
int countOccurrences(string s, string t);
//function definitions
int fact(int value) //FACTORIAL FUNCTION
{
	if(value >= 1) return value * fact(value - 1);
	else return 1;
}

int fib(int value)
{
	if(value == 1) return 0;
	else if(value == 2) return 1;
	else return fib(value - 1) + fib(value - 2);
}


void primeChecker(int number,int value) //determines if number variable is prime
{
	bool primist = false;
	if(value >= 1)
	{
		//to check if a number is prime, traverse from 2 to the number's suqre root and if it is divisible, then it is not prime
		for(int i = 2; i <= ((int)(ceil(sqrt(number)))); i++)
		{
			if(number % i == 0) primist = true;
		}
		if(primist) primeChecker(number + 1, value); //call the function recursively, iterator value shall not change
		else
		{
			cout << number << "\t";
			primeChecker(number + 1, value - 1); //call the function recursively
		}
	}
	else return;
}

void prime (int value)
{
	int primer = 2; //first prime value
	cout << primer << "\t";

	primeChecker (primer + 1, value - 1); // this the call to the helper function
	return;
}


int mult(int x, int y) //works! to change to the power method, change + to * in line 72 and 0 to 1 in line 76
{
	if(y >= 1) return (x + mult(x, y - 1));
	else return 0;
}

string reverseString(string value) //works
{
	string plus = "";
	if(value.length() > 0)
	{
		plus = value.substr(value.length() - 1, value.length());
		return plus + reverseString(value.substr(0, value.length() - 1));
	}
	else return "";
}

int countOccurrences(string all, string value) //works
{
	//relying on the fact that value is only a character and not a longer string
	if(all.length() > 0)
	{
		if(all.substr(0,1) == value) return 1 + countOccurrences(all.substr(1, all.length()), value);
		else return countOccurrences(all.substr(1, all.length()), value);
	}
	else return 0;
}

int main() {
	int count;
	int f = 5;
	//factorial
	cout << "factorial of " << f << " is " << fact(f) << endl << endl;

	//fibonacci
	for(count = 0; count < 10; count++)
	{
		cout << "Fibonacci Sequence number " << count + 1 << " is " << fib(count + 1) << endl;
	}

	//primes
	prime(10);
	//cout << (int)(ceil(sqrt(3))) << endl;
	//multiplication
	int a = 6; int b = 5;
	cout << endl << "product of " << a << " and " << b << " is " << mult(a,b) << endl << endl;

	//string reversal
	string s = "abcde";
	cout << "original string " << s << " reversed string " << reverseString(s) << endl << endl;

	//character counting
	string t = "e";
	cout << "number of occurrences of " << t[0] << " in " << s << " is " << countOccurrences(s,t) <<  endl;

	return 0;
}

