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
	emp * nextEmp;
};

//some data
const int size = 100;
int trav = 0;
emp * employees[size]; //this is the hash table

void displayEmp(emp * employees[])
{
	cout << endl << "DISPLAYING EMPLOYEES HASH MAP" << endl;

	cout << "--------------------------" << endl;
	for(int i = 0; i < size; i++)
	{
		cout << "Entry #" << i << ": ";
		emp * etrav = new emp;
		etrav = employees[i];
		while(etrav)
		{
			if(etrav -> ssn == 0)
			{
				cout << "NO ENTRIES" << endl;
				break;
			}
			else
			{
				cout << endl;
				cout << "\t ~ " << etrav -> first << " " << etrav -> last << " " << etrav ->ssn << ". ";
				etrav = etrav -> nextEmp;
			}
			cout << endl; //just for spacing
		}
	}
}

int encrypt(int data) //recursion
{
	// returns the sum of all the digits
	if (data > 0) return (data%10) + encrypt(data/10);
	else return 0;
}

void lookUpEmp(int ssn)
{
	int keyssn = encrypt(ssn);
	cout  << "QUERY STEP" << endl;

}
int main()
{
	//------ PART 0: SETTING UP --------//
	cout << "WELCOME TO ASSIGNMENT 7 BY SHAHAF DAN" << endl;
	//1. create static array of employeeeData
	for(int i = 0; i < size; i++)// initializing the has table
	{
 		emp * e = new emp;
		e->first = "";
		e->last = "";
		e->ssn = 0;
		e->nextEmp = nullptr;
		employees[i] = e;
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
			l = curLine.substr(18,14); //positions 19 to 33

			// 2. encrypt the information
			ssnEncrypt = encrypt(stoi(ssnData));
			//now encrypt has the sum of the digits

			// 3. based on the encryption, pass to the right entry in the has table

			emp * e = new emp;
			e->first = f;
			e->last = l;
			e->ssn = stoi(ssnData);
			e->nextEmp = nullptr;
			if(!employees[ssnEncrypt]) //if the entry is empty
				employees[ssnEncrypt] = e;
			else //else, create a new node and add it to the list
			{
				emp * etrav = new emp;
				etrav = employees[ssnEncrypt];
				while(etrav -> nextEmp)
				{
					etrav = etrav -> nextEmp;
				}
				etrav = e;
			}
			// 4. go to the next person - NOT NEEDED ANYMORE
		}
		dataFile.close(); //make sure to close the file
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
		lookUpEmp(checkssn);
		cout << "enter employee ssn, or 0 to finish the program" << endl;
		cin >> checkssn;
	}
	cout << "THANK YOU, HAVE A GOOD DAY!" << endl;
	return 0;
}
