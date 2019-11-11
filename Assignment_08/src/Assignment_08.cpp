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
#include <algorithm>
#include <cmath>
#include "Heap.hpp"
using namespace std;

const string filePath = "/Users/shahafdan/eclipse-workspace/Assignment_08/src/a81data.txt"; //CHANGE LOCATION LATER BASED ON ASSIGNMENT"S INSTRUCTIONS
void buildArray(int toPop[], int size, string path)
{
	int counter = 0;
	int ind = 0;
	string numbers;
	string moreNumbers;
	ifstream dataFile;
	dataFile.open(path);
	int number = 0;
	if(dataFile.fail())
	{
		cout << "COULD NOT OPEN FILE" << endl;
		throw "A81 file won't open";
	}
	else
	{
		int count;
		while(!dataFile.eof()) // while loop to read the file
		{
			dataFile >> moreNumbers;
			numbers += moreNumbers;
		}

		while(numbers.length() > 0) //while loop to populate the array
		{
			toPop[ind] = stoi(numbers.substr(counter, 3));
			cout << toPop [ind] << " ,";
			//if(toPop[ind] == 0 || numbers.length() < 2) break;
			ind++;
			counter += 3;
			if(counter + 2  > numbers.length())break;
			count ++; //keep track of amount of numbers that are in the file
		}
		cout << endl << endl << " There is a total of " << count << " numbers in the provided file" << endl << endl;
	}
	return;
}

void displayArray(int  toPrint[], int low, int high)
{
	// I am not exactly sure on why we pass the low and high parameters, but whatever
	for(int i = 0; i < (int)(ceil(sizeof(toPrint))); i++) //I hope sizeof function will work as I hope
	{
		for(int j = 0; j < 10; j++)
		{
			if(toPrint[((i * 10) + j)] == 0) break;
			cout << toPrint[((i * 10) + j)] << "\t ";
		}
		cout << endl;
	}
}

bool checkIfHeap(int toCheck[], int low, int high)
{
	//before starting: remember:
		//Left node index based heap: 2 * index + 1
		//right node index based heap: 2 * index + 2

	if( ((2 * low) + 2) > high) return true; //if the low bound is a last node in the heap:, the return true
	//recursive call // check every node recursivley until getting to the 99th item in the array (last element in the heap)
	bool leftNode = (toCheck[low] <= toCheck[(2 * low )+ 1]) && checkIfHeap(toCheck, (2*low) + 1, high);

	bool rightNode = ( (2 * low) + 2 == high) || (toCheck [low] <= toCheck [(2 * low) + 2] && checkIfHeap (toCheck, (2*low) + 2, high));

	return leftNode && rightNode; //return true only if both the rightNode and left Node are all truely a heap
}

void buildHeap(int toBuild[], int low, int high)
{
	Heap h; // createa  new heap into which we will step by step transfrom all of our elements from the array
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
	buildArray (list, 100, filePath); //change later back to p DO NOT FORGET THIS!!!!!
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


/******** TO DO  *************************/

//1. change files locations
//2. ask professor for the original files
//3. buildHeap: do we just change the array or do we build an actualy heap?
//4. don't forget to pass array by reference when making changes (void funcstions ususally)
