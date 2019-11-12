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
			revBinCarr[length] = '/0'; //now we have an array of characters that includes instructions on how to get to every possible place in the heap
			cout << "level:" << level << endl;
			trav = root;
			for(int l = 0; l < level; l++) //within the  level// 2 to the level amount of number
			{
				if (ap == 0)
				{
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
			cout << endl;
			//trav -> right = nullptr;
			//trav -> left = nullptr;
			//cout << revBin << endl;
			//trav -> right = nullptr;
			//cout << i << endl;
			//cout << trav -> up -> data;
			//trav -> left = nullptr;
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
