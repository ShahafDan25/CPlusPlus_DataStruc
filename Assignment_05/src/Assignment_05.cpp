//============================================================================
// Name        : Assignment_05.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Stack.cpp"

int main()
{
	Stack t;
	cout << "Hello" << endl << "Please enter the size of your array" << endl;
	int size = 0;
	cin >> size;
	string * array  = new string[size];
	int count = size;
	string s;
	int answer;
	cout << "select action " << endl;
	cin >>  answer;
	while(answer != 0)
	{
		cout << "enter string" << endl;
		cin >> s;
		t.push(s);
		count--;

	}
	return 0;
}
