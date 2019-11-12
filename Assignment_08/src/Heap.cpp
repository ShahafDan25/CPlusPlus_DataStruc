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

	cout << "Level: " << level << ".  index" << i << endl;

	if(i < size)
	{
		// 1) find the node we need to go to next
		node * trav = new node;
		node * travMin = new node;
		travMin = root;
		trav = root;
		int counter = 0;
		for(int i = 0; i < level; i++)
		{
			trav = trav -> left; //go to the left most node in the spoken level
			if(trav ==  nullptr)
			{
				trav -> right = nullptr;
				trav -> left = nullptr;
				trav -> data = array[i];
				break; //if the node we are currently looking at is not storing any data, that means we should insert there our number
			}
			else
			{
				travMin = trav;
				counter++;
				for(int j = 0; j < level - counter; j++)
				{
					travMin = travMin -> right;
					if(travMin == nullptr)
					{
						travMin -> right = nullptr;
						travMin -> left = nullptr;
						travMin -> data = array[i]; //populate with the right index from the passed array
						break;
					}
				}
			}
		}
		// 2) call the function recusrively again
		//first check if level needs to be increased by going to the right most node.
		//if the right most node is not empty, then increase the level
		node * trav2 = new node;
		trav2 = root;
		for(int p = 0; p < level; p++)
		{
			trav2 = trav2 -> right;
		}
		//now trav2 is pointing to the right most node in the currently spoken level
		if(trav2 == nullptr) (array, i +1, size, level); //if the right most node is NOT populated yet, then that means that not all node in the level have been populated, and we shall keep populating the same level until we run out
		else (array, i +1, size, level + 1); //if the right most node is already populated, then we can go on and move to the next level
	}
	else return; // or else, finish the function
}
