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
 * 	retreive_back ----works
 * 	display_list ----works
 * 	destroy_list
 * 	list_length ----works
 * 	search_list ----works
 * 	delete_node ----works
 */


//---------------push front function --------------------
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


//---------------- push back function --------------------
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


//----------------- get length function ---------------------
template<class dataType>
int LL<dataType>::list_length_helper(LLnode * & cur)
{
	if(cur) //if the current node is not null
		return 1 + list_length_helper(cur -> fwdPtr); // return 1 (for the node count) plus recursinally going to the next node and keep counting
	else
		return 0; //or else, return 0 because it is the end of the linked list
}
template <class dataType>
int LL<dataType>::list_length() //v
{
	//call a helper function
	return list_length_helper(llh);
}


//--------------- retrieve front function ----------------
template <class dataType>
dataType LL<dataType>::retrieve_front ()
{
	if(!llh)
		throw string ("Exception at retrieve back");
	return (llh -> theData);
}


//--------------- retrieve back function -------------------
template <class dataType>
dataType LL<dataType>::retrieve_back_helper(LLnode *& cur)
{
	if(cur -> fwdPtr)//if the current node does not have a fwdNode (that is not null)
		return retrieve_back_helper(cur -> fwdPtr);
	else
		return cur -> theData;
}
template <class dataType>
dataType LL<dataType>::retrieve_back ()
{
	return retrieve_back_helper(llh);
}


//------------------ display function --------------------
template <class dataType>
void LL<dataType>::display_list_helper(LLnode *& cur)
{
	if(cur)
	{
		cout << cur -> theData << ",  ";
		display_list_helper(cur -> fwdPtr);
	}
	else
		return;
}
template <class dataType>
void LL<dataType>::display_list() //v
{
	if(!llh)
		cout << "No nodes to display " << endl;
	else //call helper function
	{
		cout << "Displaying nodes: " << endl;
		display_list_helper(llh);
	}
	cout << endl;
}


//------------------ constructor -----------------
template <class dataType>
LL<dataType>::LL()
{
	llh = nullptr;
}


//------------------ destroy function --------------------
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


// --------------- search function --------------
template <class dataType>
bool LL<dataType>::search_list_helper(dataType data, LLnode *& cur)
{
	if(cur)
	{
		if(cur -> theData == data)
			return true;
		else
			return search_list_helper(data, cur -> fwdPtr);
	}
	return false; //return false if havent retuened true yet
}
template <class dataType>
bool LL<dataType>::search_list(dataType data)
{
	if(!llh)
		cout << "nothing to search from" << endl; return false;
	return search_list_helper(data, llh);
}


//--------------- delete function ------------------
template <class dataType>
bool LL<dataType>::delete_node_helper(dataType value, LLnode *& cur)
{
	if(cur)
	{
		if(cur -> theData == value)
		{
			LLnode * temp = new LLnode;
			temp = cur -> fwdPtr;
			cur -> fwdPtr = cur -> fwdPtr -> fwdPtr;
			delete temp;
			return true;
		}
		else
			return delete_node_helper(value, cur -> fwdPtr);
	}
	else
		return false;
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
	//case #2: body contains the value -- RECURSIVE SOLUTION
	return delete_node_helper(value ,llh);
}



