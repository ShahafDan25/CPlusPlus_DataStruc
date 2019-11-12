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
using namespace std;

//constructor
Heap::Heap()
{
	root = new node; //dynamically initialize
	root -> up = nullptr;
	root -> left =
	levels = 0; //set amount of levels in the tree (floors) to zero
}

void Heap::populateFromArray(int thatArray[], int size )
{
	root -> right = nullptr;
	root -> left = nullptr;
	root -> data = thatArray [0]; //last three lines of code initialize the root
	int indexCheck = 1; //will be associated with the current spoken index form the array we need to use ad our data
	int level = 1;
	populateHelper(thatArray, indexCheck, size, level);
	return;
}

void Heap::populateHelper(int array[], int i, int size, int level)
{

	node * trav = new node;
	trav = root; //initalize for testing and populating purposes
	node * trav2 = new node;
	trav2 = root;
	if(i < size) //check if we maxed out from our array already
	{
		for(int x = 0; x < level; x++) //go to the left most node and strat from there
		{
			trav = trav -> left; // go to the left most node
		}
		// stage 2) go to the right most node
		// if the right most node is already populated in that level, then that menas all the other nodes in that level are populated,
		// which means we have to recursively call the function again as follows:
		for(int y = 0; y < level; y++)
		{
			trav2  = trav2 -> right;
		}
		/// ---- RECURSIVE CONDITIONAL CALLS ----
		if(!trav2) /* if trav2 (aka the right most node) is populated */ populateHelper(array, i + 1, size, level + 1); // then move to the next level
		else populateHelper(array, i + 1, size, level); // then don't move to  the next level
	}
	else return; // or else, finish the function
}
