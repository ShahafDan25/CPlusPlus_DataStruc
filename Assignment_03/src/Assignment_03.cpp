//============================================================================
// Name        : Assignment_03.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include "others.cpp"
using namespace std;

int main()
{
	// factorial
		int count;
		int f=5;
		cout << "factorial of " << f << " is " << fact(f) << endl << endl;
	// Fibonocci
		for (count=0;count < 10;count++)
		{
			cout << "Fibonocci sequence number " << count+1 << " is " << fib(count) << endl;
		}
	// primes
		prime (10);
	// multiplication
		int a=6, b=5;
		cout << endl << "product of " << a << " and " << b << " is " << mult(a,b) << endl << endl;
	// string reversal
		string s = "abcde";
		cout << "original string " << s << " reversed string " << reverseString(s) << endl << endl;
	// character counting
		string t="a";
		cout << "number of occurrences of " << t[0] << " in " << s << " is " << countOccurrences(s,t) << endl;

	    return 0;
}
