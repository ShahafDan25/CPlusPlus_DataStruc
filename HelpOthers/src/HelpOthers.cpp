//============================================================================
// Name        : HelpOthers.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int total = 0; //use to hold the value of the total
bool isValid(int a)
{
	//return true if a is greater than 30, otherwise return false
	if(a > 30) //will only add the value to total if the value is greater than 30
	{
		return true;
	}
	else
	{
		return false;
	}
}

void runningTotal(int a, int & total)
{
	total += a; //change the value of total by a
}


int main()
{
	int value = 0;

	do
	{
		cout << "enter a number for the program, type 0 to terminate" << endl;
		cin >> value; //put user input into value variable
		if(isValid(value))//check for the value's validity
		{
			runningTotal(value, total);//if valid, add to total
		}
	}while(value != 0);

	cout << "TOTAL: " << total << endl;
	cout << "PROGRAM ENDING, have a good day" << endl;
	return 0;
}
