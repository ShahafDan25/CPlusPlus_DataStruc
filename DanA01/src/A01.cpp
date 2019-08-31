//============================================================================
// Name        : A01.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;


struct LLnode
{
	string theData;
	LLnode * fwdPtr;
};

//MAKE SURE TO DO FOR EVERYTHING IF NULLPTR STATEMENT

void push_front(LLnode * &llh, string newData)
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

void push_back(LLnode * &llh, string newData)
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

int list_length(LLnode * &llh) //v
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

string retrieve_front (LLnode * &llh)
{
	return (llh -> theData);
}

string retrieve_back (LLnode * &llh)
{
	LLnode * trav = new LLnode;
	trav = llh; // that way we do not hurt llh
	while(trav -> fwdPtr)
	{
		trav = trav -> fwdPtr;
	}
	return trav -> theData;

}

void display_nodes(LLnode * &llh) //v
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

int main()
{
	LLnode * theLLHeader1 = nullptr;
	cout << "Main: number of nodes in empty list " << list_length(theLLHeader1) << endl;
	display_nodes(theLLHeader1);
	push_front(theLLHeader1, "aaaaa");
	push_back(theLLHeader1, "bbbbb");
	push_front(theLLHeader1, "before aaaaa");
	push_back(theLLHeader1, "after bbbbb");
	cout << "Main: number of nodes after 4 pushed: " << list_length(theLLHeader1) << endl;
	display_nodes(theLLHeader1);
	cout << "Main: retrieve front: " << retrieve_front (theLLHeader1) << endl;
	cout << "Main: retrieve back: " << retrieve_back (theLLHeader1) << endl;
	cout << endl;

	LLnode * theLLHeader2 = nullptr;

	push_front(theLLHeader2, "33333");
	push_front(theLLHeader2, "22222");
	push_front(theLLHeader2, "11111");
	push_back(theLLHeader2, "44444");
	push_back(theLLHeader2, "55555");
	push_back(theLLHeader2, "66666");
	display_nodes (theLLHeader2);

	return 0;
}
