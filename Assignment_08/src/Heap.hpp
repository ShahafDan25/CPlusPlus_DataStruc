/*
 * Heap.hpp
 *
 *  Created on: Nov 10, 2019
 *      Author: shahafdan
 */

#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <string>
#include <iomanip>
#include <iostream>
#include <set>
using namespace std;

class Heap
{
private:
	struct node
	{
		int data;
		node * right;
		node * left;
		node * up;
	};
	node * root; //head, top most node // should be the lowest value

	int levels; //will keep track on how many floors are there in the heap tree structure
public:
	Heap(); //constructor for a heap, initialize the head / root node
	void populateFromArray(int array[], int size);
	void populateHelper(int array[], int i, int size, int floor);
	void sortIt(int size);
	void sortHelper(int counter, int size, int floor);
	void exchange(node *& p, node *& n);
	void heapify(int array[], int low, int high);


};




#endif /* HEAP_HPP_ */
