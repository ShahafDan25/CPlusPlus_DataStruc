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


void displayEmp(emp e)
{

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
	const int size = 100;
	emp employees[size]; //this is the hash table
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
		//int counter = 0; //set counter for employees read from file
		string curLine;
		string f;
		string l;
		string ssnData;
		int ssnEncrypt;
		//close file after reading from it
		while(getline(dataFile, curLine)) //while the file is not empty, move to curLine the current line from the file
		{
			// 1. read the data from the curLine
			ssnData = curLine.substr(0,9); //position 0 to 8
			f = curLine.substr(9,19); //position 9 to 18
			l = curLine.substr(19,33); //positions 19 to 33

			// 2. encrypt the information
			ssnEncrypt = encrypt(stoi(ssnData));
			cout << ssnEncrypt << endl;
			//now encrypt has the sum of the digits

			// 3. based on the encryption, pass to the right entry in the has table
			//emp * e = new emp; //first create a new emp structure
			//e->first = f;
			//e->last = l;
			//e->ssn = stoi(ssnData);
			//3.5: check for space in the list
			//if (employees[ssnEncrypt].empList == nullptr) employees[ssnEncrypt].empList.push_back(e); //if this is the head of the list;
			//else employees[ssnEncrypt].empList->push_back(e);
			// 4. go to the next person

		}
		dataFile.close();
	}

	//------ PART 2: DISPLAYING ALL --------//
	for(int d = 0; d < size; d++)
	{

		if(employees[d].first != "") displayEmp(employees[d]);
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
