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

	cout << "Hello" << endl << "Please enter the size of your array ";
	int size = 0;
	cin >> size;
	string value;
	Stack s(size);
	int answer = 0;
	do
	{
		cout << "select: push (1) | top (2) | pop (3) | destroy last (4) | destroy all (5) | display (6) | exit (9) \t ";
		cin >> answer;
		if(answer == 1) //push
		{

			cout << "enter value ";
			cin >> value;
			s.push(value);

		}
		else if(answer == 2) //top
		{
			if(s.top(value)) cout << "Top value in the last stack " << value << endl;
			else cout << "stack is empty" << endl;
		}
		else if(answer == 3) //pop
		{
			if(s.pop(value)) cout << "top value after popping: " << value << endl;
			else cout << "stack is empty" <<endl;
		}
		else if(answer == 4)
		{
			cout << endl << "--- DELETING LAST ARRAY ---" << endl;
			s.destroy();
		}
		else if (answer == 5)
		{
			cout << "--- DESTROYING ALL ---" << endl;
			s.destroyAll();
		}
		else if (answer == 6) //print all, not mandatory in the assignment
		{
			cout << endl << "--- PRINTING ALL ---" << endl;
			s.printAll();
		}
		else if(answer == 9) cout << "Goodbye, ending program" << endl;
		else cout << "not a convenient answer" << endl;

	}while(answer != 9);


	return 0;
}
