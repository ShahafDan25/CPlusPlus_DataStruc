//============================================================================
// Name        : Assignment_07.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iostream>
#include <set>
#include <list>
using namespace std;



struct emp
{
	int ssn;
	string first;
	string last;
	list <emp> * empList;
};


void displayEmp(emp e)
{

}


int main()
{
	//------ PART 0: SETTING UP --------//
	cout << "WELCOME TO ASSIGNMENT 7 BY SHAHAF DAN" << endl;
	//1. create static array of employeeeData
	const int size = 100;
	emp employees[size]; //this is the hash table
	for(int i = 0; i < size; i++)// initializing the has table
	{
		employees[i].ssn = 0;
		employees[i].first = NULL;
		employees[i].last = NULL;
		employees[i].empList = nullptr;
	}

	//------ PART 1: READING DATA --------//
	//------ PART 2: DISPLAYING ALL --------//
	for(int d = 0; d < size; d++)
	{

		if(employees[d].first != NULL) displayEmp(employees[d]);
	}
	//------ PART 3: QUERY EMPLOYEES --------//
	int checkssn = 0;
	cout << "enter employee ssn: " << endl;
	cin >> checkssn;
	while(checkssn != 0)
	{
		//print the right employee
		cout << "enter employee ssn: " << endl;
		cin >> checkssn;
	}
	return 0;
}
