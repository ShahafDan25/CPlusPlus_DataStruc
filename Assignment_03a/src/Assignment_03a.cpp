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

//function declarations
int fact(int value);
int fib (int value);
int primeHelper(int value);
void prime(int value);
//function definitions
int fact(int value) //FACTORIAL FUNCTION
{
	if(value >= 1)
	{
		return value * fact(value - 1);
	}
	else
	{
		return 1;
	}
}

int fib(int value)
{
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


}

void prime (int value)
{
	int primeNum = 2;
	while(value > 0)
	{
		cout << primeHelper(primeNum) << "\t";
		value --;
	}


}


int mult(int x, int y) //works! to change to the power method, change + to * in line 72 and 0 to 1 in line 76
{
	if(y >= 1)
	{
		return (x + mult(x,y-1));
	}
	else
	{
		return 0;
	}
}

string reverseString(string value)
{
	string plus = "";
	if(value.length() > 0)
	{
		plus = value.substr(value.length() - 1, value.length());
		return plus + reverseString(value.substr(0, value.length() - 1));
	}
	else return "";
}

int countOccurrences(string all, string value)
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
//	for(count = 0; count < 3; count++)
//	{
//		cout << "Fibonacci Sequence number " << count + 1 << " is " << fib(count) << endl;
//	}
	cout << "fib(10) =    " << fib(10) << endl;

	//primes
	prime(10);

	int a = 6;
	int b = 5;
	cout << endl << "product of " << a << " and " << b << " is " << mult(a,b) << endl << endl;
	//string reversal
	string s = "abcde";
	cout << "original string " << s << " reversed string " << reverseString(s) << endl << endl;

	//character counting
	string t = "e";
	cout << "number of occurrences of " << t[0] << " in " << s << " is " << countOccurrences(s,t) <<  endl;

	//cout << _gcd(45,9) << endl;
	return 0;
}

