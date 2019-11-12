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
	root -> left = nullptr;
	root -> up  = nullptr;
	levels = 1; //set amount of levels in the tree (floors) to zero
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
	node * parent = new node;
	node * trav2 = new node;
	trav2 = root;
	int counter = 1;
	if(i < size) //check if we maxed out from our array already
	{
		while(trav) //as long as the node we are looking at is not nullptr:
		{
			//trav is at the very beginning the root
			if(trav -> left == nullptr)
			{
				parent = trav;
				trav = trav -> left;
				trav -> data = array [i];
				trav -> up = parent;
				trav -> right = nullptr;
				trav -> left = nullptr;
				break;
			}
			else if (trav -> right == nullptr)
			{
				parent = trav;
				trav = trav -> right;
				trav -> data = array [i];
				trav -> up = parent;
				trav -> right = nullptr;
				trav -> left = nullptr;
				break; //we break because we just populated another leaf of the heap tree
			}
			else //both the left nor the right is populated >>> then move to the next level!
			{
				if(!trav -> up) //if trav is root
				{
					trav = root;
					for(int j = 0; j < level; j++)
					{
						trav = trav -> left;
						// go to the left most node, starting a new level

					}
				}
				else
				{
					trav = trav -> up -> right;
				}

			}
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
