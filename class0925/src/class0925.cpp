//============================================================================
// Name        : class0925.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <list>
using namespace std;

int main()
{
	//CONCEPT : an uncounded array is called a vector, but if we include an array, we can define an array item
	array <int, 10> a; // declare a static vector of type int with a size for 10 elements
	a [3] = 5; //set the 4th element of the vector to 5
	int i;
	a [8] = i; //i is yet to be defined, so we set the 9th value of a to 0 (default value of i)
	i = a[2] + 66; // set i to the third value of the vector a plus 66
	a[10] = 0;  // because it is a vector, it does not have a set size, unlike array. Therefore in this line the next item (11th element) of teh vector is created and is given the value 0

	i = a.at(3); //we can use the at function to get the element at the third (fourth element) position
	cout << i << endl;

	//CONCEPT:  a vector is a built in linked list!!
	//in order to do so we need to #include <list>
	list <int> LL; //define a vector named list, fpr type int called LL
	LL.push_front(2); //the push front function the we builded is a built in function of the list type
	LL.push_front(3);
	LL.push_back(4); //the push back function we programed
	LL.push_back(5);
	cout << "size of LL:  " << LL.size() << endl; //LL.size() gives us the amount of elemsnts
	LL.remove(2); //removes the item at the second position
	cout << "size of LL:  " << LL.size() << endl;
	LL.pop_back(); //removes the last item in the list


	return 0;
}
