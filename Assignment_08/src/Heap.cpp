/*
 * Heap.cpp
 *
 *  Created on: Nov 10, 2019
 *      Author: shahafdan
 */

#include "Heap.hpp"//include class declaration and definition
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

//constructor
Heap::Heap()
{
	root = new node; //dynamically initialize
	root -> right = nullptr;
	root -> left = nullptr;
	levels = 1; //set amount of levels in the tree (floors) to zero
}

void Heap::populateFromArray(int thatArray[], int size )
{
	root -> right = nullptr;
	root -> left = nullptr;
	root -> data = thatArray [0]; //last three lines of code initialize the root
	populateHelper(thatArray, 1, size, 1);
	return;
}

void Heap::populateHelper(int array[], int i, int size, int level) //each level would populate a whole level
{

	node * trav = new node;
	trav = root; //initalize for testing and populating purposes
	node * parent = new node;
	bool zeroCorruption = false;
	if(i < size) //check if we maxed out from our array already
	{

		// stage 1) use a binary number of the level to run the code
		int dec = pow(2, level); //store in the new integer (dec) the value of 2 to the power the level
		for(int p = 0; p < dec; p++)
		{

			trav = root;
			string bin = ""; //clear string
			string revBin = ""; //clear string
			int r; // to be used as the remiainder
			int ap = p;
			while(ap != 0)
			{
				r = ap % 2;
				ap = ap / 2;
				if(r == 1) bin += "1";
				else bin += "0";
			}// end of while

			int length = bin.size(); //get the size of the string
			char binCarr[length + 1];
			bin.copy(binCarr, length + 1);
			binCarr[length] = '/0';

			//now reverse it
			for(int x = sizeof(binCarr) - 1; x >= 0; x--)
			{
				revBin += binCarr [x];
			} //now revBin has our binary number of level digits long
			//0 - left turn
			//1 - right turn
			//to do so, first convert the string to an array of characters
			length = revBin.size();
			char revBinCarr[length + 1];
			revBin.copy(revBinCarr, length + 1);
			int revBinInt = stoi(revBin);
			revBinCarr[length] = '/0'; //now we have an array of characters that includes instructions on how to get to every possible place in the heap
			trav = root;
			for(int l = 0; l < level; l++) //within the  level// 2 to the level amount of number
			{
				if (ap == 0) //fix zero corruption situation
				{
					zeroCorruption = true;
					break;
				}
				else if(revBinCarr[l] == '1')
				{
					parent = trav;
					trav -> up = parent;
					trav = trav -> right;
				}

				else if(revBinCarr[l] == '0')
				{
					parent = trav;
					trav -> up = parent;
					trav = trav -> left;
				}

			}
			if(zeroCorruption)
			{
				trav = root;
				while(trav -> left)
				{
					trav = trav -> left;
				}
				//trav = trav -> left;
				trav -> data = array[i];
				zeroCorruption = false;
			}
			trav -> right = nullptr;
			trav -> left = nullptr;
			trav ->  data = array[i];
			i++;
			//cout << i << endl;
			if (i >= size) break;//break if bounded

		}
		//========== RECURSIVE CALL ===========
		populateHelper(array, i, size, level + 1);
	}
	else return; // or else, finish the function
}

void Heap::sortIt(int array[], int size)
{
	//call the helper to be active recursively
	//sortHelper(1, size, 1);
	int temp = 0;
	for(int k = size; k > 0; k--)
	{
		temp = array[k];
		array[k] = array [0];
		array[0] = temp;
		heapify(array, 0, k - 1);
	}// end sorting for loop
}

void Heap::sortHelper(int i, int size, int floor) //every call, an entire floor will be sorted
{
	//once again we use the binary accessing methodology
	/*node * trav = new node;
	node * parent = new node;
	bool zeroCorruption = false;
	int dec = pow(2, floor); //store in the new integer (dec) the value of 2 to the power the level
	for(int p = 0; p < dec; p++)
	{
		trav = root; //set it to the root for every node we will go through in the current level (floor)
		string bin = ""; //clear string
		string revBin = ""; //clear string
		int r; // to be used as the remiainder
		int ap = p;
		cout << "Ap:" << ap << endl;
		while(ap != 0)
		{
			r = ap % 2;
			ap = ap / 2;
			if(r == 1) bin += "1";
			else bin += "0";
		}// end of while
		int length = bin.size(); //get the size of the string
		char binCarr[length + 1];
		bin.copy(binCarr, length + 1);
		binCarr[length] = '/0';
			//now reverse it
		for(int x = sizeof(binCarr) - 1; x >= 0; x--)
		{
			revBin += binCarr [x];
		} //now revBin has our binary number of level digits long
	//0 - left turn
		//1 - right turn
		//to do so, first convert the string to an array of characters
		length = revBin.size();
		char revBinCarr[length + 1];
		revBin.copy(revBinCarr, length + 1);
		int revBinInt = stoi(revBin);
		revBinCarr[length] = '/0';

		for(int l = 0; l < floor; l++) //within the  level// 2 to the level amount of number
		{
			if (ap == 0) //fix zero corruption situation
			{
				zeroCorruption = true;
				break;
			}
			else if(revBinCarr[l] == '1')
			{
				parent = trav;
				trav -> up = parent;
				trav = trav -> right;
			}

			else if(revBinCarr[l] == '0')
			{
				parent = trav;
				trav -> up = parent;
				trav = trav -> left;
			}

			}
			if(zeroCorruption)
			{
				trav = root;
				while(trav -> left)
				{
					trav = trav -> left;
				}
				//trav = trav -> left;
				zeroCorruption = false;
			}
		//NOW: TRAV HOLDS THE NODE WE WANT TO ACCESS

	} //end of for*/
}

void Heap::heapify(int arr[], int low, int high) //trasnfrom the subtree bounded by low and high to a heap
{
	int ind; // to use as our large index
//	node * temp = new node;
//	temp -> right = nullptr;
//	temp -> up = nullptr;
//	temp -> left = nullptr;
//	temp -> data = arr[low];
	int temp = arr [low]; // use as a temporary value for the ineteger in the array
	ind = (2 * low) + 1; //code inspired by the man, the myth, the legend: Malik
	while(ind < high + 1)
	{
		if(ind < high)
		{
			if(arr[ind] < arr [ind + 1]) ind += 1;
		}
		if(temp > arr [ind]) break; // that means that the subtree is already in the heap
		else
		{
			arr[low] = arr[ind];
			low = ind; // go to the substree to restore the heap (once against, code and comments are mostly from the text)
			ind = (2 * low) + 1;
		}
	} // end of while
	arr[low] = temp; //Restoring by insertion
	return;

}




/// some lines for convenience
