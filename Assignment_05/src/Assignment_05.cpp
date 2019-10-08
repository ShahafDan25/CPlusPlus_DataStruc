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

	/*cout << "Hello" << endl << "Please enter the size of your array ";
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
			else cout << "stack is empty after poping" << endl;
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

			//s(size); //after we destroyed everything, we need to reinitialize it, so we call the constructor again
		}
		else if (answer == 6) //print all, not mandatory in the assignment
		{
			cout << endl << "--- PRINTING ALL ---" << endl;
			s.printAll();
		}
		else if(answer == 9) cout << "Goodbye, terminating program" << endl;
		else cout << "not a convenient answer" << endl;

	}while(answer != 9);

*/
	Stack s(5);
	string st;
	bool b;
	s.push("aaaaa");
	s.push("bbbbb");
	s.push("ccccc");
	s.push("ddddd");
	s.push("eeeee");

	cout << "Main: Start of part 1" << endl;
	b = s.top(st);
	cout << "main: top of stack " << st << endl;
	b = s.pop(st);
	cout << "main: new top of stack after pop " << st << endl;
	b = s.pop(st);
	cout << "main: just popped this ->" << st << endl;
	b = s.top(st);
	cout << "main: just popped this ->" << st << endl;
	b = s.pop(st);
	cout << "main: just popped this ->" << st <<endl;
	b = s.top(st);
	cout << "main: just popped this ->" << st << endl;
	b = s.top(st);
	if(b)
	{
		cout << "main: stack non-empty when it should be empty" << endl;
		return 4;
	}
	else
	{
		cout << "main: stack empty when its empty" << endl;
	}

	cout << endl << "main: start of part 2" << endl;
	s.push("aaaaa");	// 1st element 1st array
	s.push("bbbbb");
	s.push("ccccc");
	s.push("ddddd");
	s.push("eeeee");
	s.push("fffff");	// 1st element 2nd array
	s.push("ggggg");
	s.push("hhhhh");
	s.push("iiiii");
	s.push("jjjjj");
	s.push("kkkkk");	// 1st element 3rd array
	b = s.top(st);
	cout << "main: top of stack " << st << endl;
	cout << "main: before while loop " << st << endl;
	b = s.pop(st);
	while (b)
	{
		cout << "main: element of stack " << st << endl;
		b=s.pop(st);
	}
	cout <<"main: before destroy"<< endl;
	s.destroy();
	cout <<"main: after destroy"<< endl;
	s.push("zzzzz");
	b=s.top(st);
	cout << "main: new top of stack " << st << endl;
	s.destroy();

	return 0;
}
