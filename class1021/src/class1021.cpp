//============================================================================
// Name        : class1021.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//new terms
//*** instrumentation: counting and keeping track of traversing and looping
//*** binary serach requires that the array is sorted
//average time for sorting is O(n^2)


//linear search algorithm
int linearSearch(int array [], int high, int target, int &numIter)
{
	int i = 0;
	bool found = false; // because we have not found the item yet
	while( i < high && !found)
	{
		numIter++;
		if(array[i] == target) found = true;
		else i++;
	}

	if(found) return i;
	else return -1;
}

//bubbleSort algorithm
void bubbleSort(int array[], int high, int &numIter)
{
	int i,j,temp;
	for(i = 0 ;i < high; i++)
	{
		for(j = 0; j < high; j++)
		{
			numIter++;
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

	for(i = 0; i <= high; i++)
	{
		cout << array[i] << endl;
	}
}

//binary search algorithm
int binarySearch(int array[], int high, int target, int &numIter)
{
	int first = 0;
	int mid = 0;
	bool found = false;
	while (first <= high  && !found)
	{
		mid = (first + high) /2;
		numIter++;
		if(array[mid] == target) found = true;
		else if (array[mid] > target) high = mid - 1;
		else first = mid + 1;
	}

	if(found) return mid;
	else  return -1;
	return 0;
}


int main()
{
	cout << "code from class October 21st" << endl << "---------------------------------" << endl << endl;
	int array [12] = {5,2,9,4,1,0,11,10,12,3,6,7}; //rendomly chosen integerss
	int numIter = 0;
	cout << "i = " << linearSearch(array, 11, 10, numIter) << endl;  //pass the  array, with 11+1 elements, looking for ten, passing the instrumentation variable
	cout << "numIter = " << numIter << endl;
	//now calling the bubble sort function
	cout << endl << endl;
	numIter = 0;
	bubbleSort(array, 11, numIter);
	cout << "numIter = " << numIter << endl;
	cout << endl << endl;
	//now running binary search
	numIter = 0;
	int b = binarySearch(array, 11, 6, numIter);
	if(b < 0) cout << "not found" << endl;
	else cout << "found" << endl;
	cout << "numIter = " << numIter << endl;
	cout << endl << endl;
	return 0;
}
