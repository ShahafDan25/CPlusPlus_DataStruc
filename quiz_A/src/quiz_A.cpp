//============================================================================
// Name        : quiz_A.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void abcfunc(int * intpoint) //only passes a copy of the address
{
	*intpoint++; //increases the address by 4 bits

	cout << intpoint << "   " << *intpoint << endl;
	*intpoint = *intpoint + 1; //increases the value by 1
	cout << intpoint << "   " << *intpoint << endl;

}

int main()
{
	int i = 7; //int i store the value 10
	int * p = new int; //p is dynmically declared to point to an integer
	p = &i; // p points to the address of i
	cout << p << "   " << *p << endl;

	abcfunc(p);

	cout << p << "   " << *p << endl;


	cout << "------13----------" << endl;
	int * temp = new int;
	int y = 6;
	temp = &y;
	cout << temp << endl;
	temp++;
	cout << temp << endl;
	cout << "-------15---------" << endl;
	int myints[10] = {0,1,2,3,4,5,6,7,8,9};
	cout << &myints[0] << " " << &myints[1] <<  " " << &myints[2] << endl;
	cout << "-------16---------" << endl;
	long long int myints2[100];
	cout << &myints2[0] << " " << &myints2[1] << " " << &myints2[2] <<  endl;
	return 0;
}
