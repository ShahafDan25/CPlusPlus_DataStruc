//============================================================================
// Name        : class0821.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int i;
	int j;
	cout << "address of i: " << &i << endl; //display the address of the integer variable i
	cout << "address of j: " << &j << endl;

	int * p; //create a pointer to an integer, a pointer stores an address
	p = new int; //dynamically allocate
	cout << "the address of p: " << &p << endl;
	cout << "the address stored in p: " << p << endl;

	// cannot get the address of a function,s o trying to get the address of main will result of an error.
	//cout << &main << endl; // this for example wont work

	float f = static_cast<float>(i); //static cast is used to convert variable types. In this example it converts i into a float, and stores it in f which is declared as a float

	float * l; //define a pointer to a float variable
	p = reinterpret_cast<int*>(l); //converts the type of data to which the pointer in pointing
	//in this example it converts the type of pointer in l from a float pointer to an integer pointer, and stores it in p;
	return 0;


}
