/*
 * LL.cpp
 *
 *  Created on: Sep 23, 2019
 *      Author: shahafdan
 */

#include "LL.hpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <set>
using namespace std;


//FOR ASSIGNMENT FOR:
/*
 *
 * Turn the following functions toe recursive functions
 * 	push_back
 * 	retreive_back
 * 	display_list
 * 	destroy_list
 * 	list_length ----works
 * 	search_list
 * 	delete_node
 */
template <class dataType>
void LL<dataType>::push_front( dataType newData)
{
	if(!llh)
	{
		LLnode * newNode = new LLnode;
		newNode -> theData = newData;
		newNode -> fwdPtr = nullptr;
		llh = newNode;
	}
	else
	{
		LLnode * trav = new LLnode;
		trav = llh;
		LLnode * newNode = new LLnode;
		newNode -> theData = newData;
		newNode -> fwdPtr = trav;
		llh = newNode;
	}
}

template <class dataType>
void LL<dataType>::push_back( dataType newData)
{

	LLnode * trav = new LLnode;
	if(!llh)
	{
		llh = new LLnode;
		llh -> theData = newData;
		llh -> fwdPtr = nullptr;
	}
	else
	{
		LLnode * newNode = new LLnode;
		newNode -> theData = newData;
		newNode -> fwdPtr = nullptr;

		trav = llh;
		while(trav -> fwdPtr)
		{
			trav = trav -> fwdPtr;
		}
		trav -> fwdPtr = newNode;
	}
}
template<class dataType>
int LL<dataType>::list_length_helper(LLnode * & cur)
{
	if(cur) //if the current node is not null
	{
		return 1 + list_length_helper(cur -> fwdPtr); // return 1 (for the node count) plus recursinally going to the next node and keep counting
	}
	else
	{
		return 0; //or else, return 0 because it is the end of the linked list
	}
}

template <class dataType>
int LL<dataType>::list_length() //v
{
	//call a helper function
	return list_length_helper(llh);

}



template <class dataType>
dataType LL<dataType>::retrieve_front ()
{
	if(!llh)
		throw string ("Exception at retrieve back");
	return (llh -> theData);
}

template <class dataType>
dataType LL<dataType>::retrieve_back ()
{
	LLnode * trav = new LLnode;
	trav = llh; // that way we do not hurt llh
	if(!llh)
		throw string ("Exception at retrieve back");
	while(trav -> fwdPtr)
	{
		trav = trav -> fwdPtr;
	}
	return trav -> theData;

}

template <class dataType>
void LL<dataType>::display_list() //v
{
	LLnode * trav = new LLnode;
	trav = llh;
	if(!llh)
	{
		cout << "No nodes to display " << endl;
	}
	else
	{
		cout << "Displaying nodes: " << endl;
		while(trav)
		{
			cout << trav -> theData << ", ";
			trav = trav -> fwdPtr;
		}
	}
	cout << endl;
}

// default constructor
template <class dataType>
LL<dataType>::LL()
{
	llh = nullptr;
}

//PART 3 FUNCTION
template <class dataType>
void LL<dataType>::destroy_list()
{
	if(!llh)
	{
		cout << "nothing to destroy :)" << endl;
		return;
	}
	while(llh) //as long as llh is not a nullptr
	{
		LLnode * temp = new LLnode;
		temp = llh;
		llh = llh -> fwdPtr;
		delete temp;
	}
	llh = nullptr;
}

template <class dataType>
bool LL<dataType>::search_list(dataType data)
{

	bool found = false;

	if(!llh)
	{
		cout << "nothing to search from :)" << endl;
		return found;
	}

	LLnode * trav = new LLnode;
	trav = llh;
	while(trav) //as long as trav (temp for llh) is not nullptr, execute this code
	{
		if(trav -> theData == data)
		{
			found = true;
			break;
		}
		trav = trav -> fwdPtr;
	}
	return found;
}

template <class dataType>
bool LL<dataType>::delete_node(dataType value)
{


	if(!llh) //case #0: no linked list has been created yet
	{
		cout << "nothing to delete from :)" << endl;
		return true;
	}
	//case #1: llh contains the value
	if(llh -> theData == value)
	{
		LLnode * temp = new LLnode;
		temp = llh;
		llh = llh -> fwdPtr;
		delete temp;
		return true;
	}
	//case #2: body contains the value
	LLnode * trav = new LLnode;
	trav = llh;
	while(trav -> fwdPtr)
	{
		if(trav -> fwdPtr -> theData == value)
		{
			LLnode * temp = new LLnode;
			temp = trav -> fwdPtr;
			trav -> fwdPtr = trav -> fwdPtr -> fwdPtr;
			delete temp;
			return true;
		}
		trav = trav -> fwdPtr;
	}
	return false;
}



