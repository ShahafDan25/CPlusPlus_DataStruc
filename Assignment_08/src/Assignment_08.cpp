//============================================================================
// Name        : Assignment_08.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ostream>
using namespace std;

void buildArray(int toPop[], int size, string path)
{
	int counter = 0;
	int index = 0;
	string numbers;
	ifstream dataFile;
	dataFile.open("/CS20/a81data.txt");
	int number;
	if(dataFile.fail())
	{
		cout << "COULD NOT OPEN FILE" << endl;
		throw "A81 file won't open";
	}
	else
	{
		while(getline(dataFile, numbers))
		{
			cout << "Data File: " << numbers << endl;
		}
	}

	for(int i = 0; i < size; i++)
	{

		number = stoi(numbers.substr(counter, 3));
		if(number == NULL) break;
		else
		{
			toPop[i] = number;
		}
		counter += 3;
	}


	return;
}

void displayArray(int toPrint[], int low, int high)
{
	// I am not exactly sure on why we pass the low and high parameters, but whatever
	for(int i = 0; i < sizeof(toPrint) / 10; i++) //I hope sizeof function will work as I hope
	{
		for(int j = 0; j < 10; j++)
		{
			cout << toPrint[((i * 10) + j)] << " ";
		}
		cout << endl;
	}
}

bool checkIfHeap(int toCheck[], int low, int high)
{

	return false;
}

void buildHeap(int toBuild[], int low, int high)
{
	return;
}

void heapSort(int toSort[], int low, int high)
{

	return;
}


int main() {
	int low, high;
	low = 0;			// low array index
	high = 99;			// high array index
	bool b;
	int list[100];
	string p ="c:/CS20/a81data.txt";
	cout << "main: building first array (from a71data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying first array" << endl << endl;
	displayArray (list, low, high);
	cout << endl;
	b=checkIfHeap (list, low, high);
	if (b)
		cout << "main: the first array is already a heap" << endl << endl;
	else
		cout << "main: the first array is not a heap" << endl << endl;
	cout << "main: now building heap" << endl;
	buildHeap (list, low, high);
	cout << "main: now displaying first array after heaping" << endl << endl;
	displayArray (list, low, high);
	b=checkIfHeap (list, low, high);
	if (b)
		cout << endl << "main: after heaping, the first array is a heap" << endl << endl;
	else
	{
		cout << endl << "main: after heaping, the first array is not a heap" << endl;
		return 4;
	}
	p ="c:/CS20/a82data.txt";
	cout << "main: building second array (from a72data.txt)" << endl;
	buildArray (list, 100, p);
	cout << "main: displaying second array" << endl << endl;
	displayArray (list, low, high);
	heapSort (list, low, high);
	cout << endl << "main: displaying second array, which should now be sorted" << endl << endl;
	displayArray (list, low, high);
	return 0;
}
