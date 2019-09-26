//============================================================================
// Name        : class0925.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
using namespace std;

int main()
{
	array <int, 10> a; // declare a static vector of type int with a size for 10 elements
	a [3] = 5; //set the 4th element of the vector to 5
	int i;
	a [8] = i; //i is yet to be defined, so we set the 9th value of a to 0 (defualt value of i)
	i = a[2] + 66; // set i to the third value of the vector a plus 66
	a[10] = 0;  // because it is a vector, it does not have a set size, unlike array. Therefore in this line the next item (11th element) of teh vector is created and is given the value 0

	i = a.at(3); //we can use the at function to get the element at the third (fourth element) position
	cout << i << endl;



	return 0;
}
