//============================================================================
// Name        : Assignment_05.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Stack.hpp"

int main()
{

	cout << "Hello" << endl << "Please enter the size of your array" << endl;
	int size = 0;
	cin >> size;
	string value;
	Stack s(size);
	int answer = 0;
	do
	{
		cout << "enter action" << endl;
		cin >> answer;
		if(answer == 1)
		{

			cout << "enter value" << endl;
			cin >> value;
			s.push(value);

		}

	}while(answer != 9);


	return 0;
}
