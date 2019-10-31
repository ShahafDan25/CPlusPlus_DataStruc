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
#include <sstream>
#include <fstream>
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

//some data
const int size = 100;
int trav = 0;
emp employees[size]; //this is the hash table

void displayEmp(emp employees[])
{
	for(int i = 0; i < size; i++)
	{
		if(employees[i].ssn == 0) cout << "entry " << i << ": has no employees!" << endl;
		else
		{
			cout << "entry " << i << ": " << employees[size].first << " " <<  employees[i].last << " " << employees[size].ssn << ". " << endl;

			for (list <emp>::iterator it = employees[i].empList -> begin(); it != employees[i].empList -> end(); ++it)
			{
				cout << "\t" << it -> first << " " << it -> last << " " << it -> ssn << ". " << endl;
			}

		}

	}
}

int encrypt(int data) //recursion
{
	// returns the sum of all the digits
	if (data > 0) return (data%10) + encrypt(data/10);
	else return 0;
}

int main()
{
	//------ PART 0: SETTING UP --------//
	cout << "WELCOME TO ASSIGNMENT 7 BY SHAHAF DAN" << endl;
	//1. create static array of employeeeData

	for(int i = 0; i < size; i++)// initializing the has table
	{
		employees[i].ssn = 0;
		employees[i].first = ""; //setting to NULL
		employees[i].last = ""; //setting to NULL
		employees[i].empList = nullptr;
	}

	//------ PART 1: READING DATA --------//
	ifstream dataFile; //NOTE:::: YOU MIGHT NEED TO CHANGE THE LOCATION OF THE FOLDER!!
	dataFile.open("/Users/shahafdan/eclipse-workspace/Assignment_07/src/Data.txt", ifstream::in);
	//if cannot open file:
	if(dataFile.fail())
	{
		cout << "COULD NOT READ DATA FROM FILE" << endl;
		throw "data file won't open";
	}// else read from file
	else
	{
		string curLine;
		string f;
		string l;
		string ssnData;
		int ssnEncrypt;
		//close file after reading from it
		while(getline(dataFile, curLine, '\n')) //while the file is not empty, move to curLine the current line from the file
		{
			// 1. read the data from the curLine
			ssnData = curLine.substr(0,9); //position 0 to 8
			f = curLine.substr(9,9); //position 9 to 18
			l = curLine.substr(18,12); //positions 19 to 33

			// 2. encrypt the information
			ssnEncrypt = encrypt(stoi(ssnData));


			//now encrypt has the sum of the digits

			// 3. based on the encryption, pass to the right entry in the has table
			if(employees[ssnEncrypt].ssn == 0)
			{
				employees[ssnEncrypt].first = f;
				employees[ssnEncrypt].last = l;
				employees[ssnEncrypt].ssn = stoi(ssnData);
			}
			else
			{
				emp * e = new emp;
				e -> first = f;
				e -> last = l;
				e -> ssn = stoi(ssnData);
				e -> empList = nullptr;
				employees[ssnEncrypt].empList->push_back(*e);
			}

			// 4. go to the next person

		}
		dataFile.close();
	}

	//------ PART 2: DISPLAYING ALL --------//
	displayEmp(employees);

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
