/*
 * LL.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: shahafdan
 */

#include "LL.hpp"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

void LL::push_front( string newData)
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

void LL::push_back( string newData)
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

int LL::list_length() //v
{
	int count = 0;
	LLnode * trav = new LLnode;
	trav = llh;
	if(!llh)
	{
		return 0;
	}
	else
	{
		while(trav)
		{
			count ++;
			trav = trav -> fwdPtr;
		}
		return count;
	}

}

string LL::retrieve_front ()
{
	if(!llh)
		throw string ("Exception at retrieve back");
	return (llh -> theData);
}

string LL::retrieve_back ()
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

void LL::display_list() //v
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
LL::LL()
{
	llh = nullptr;

}

//PART 3 FUNCTION
void LL::destroy_list()
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

bool LL::search_list(string data)
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

bool LL::delete_node(string value)
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
