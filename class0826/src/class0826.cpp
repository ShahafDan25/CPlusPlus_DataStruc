//============================================================================
// Name        : class0826.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


// reviewed pass by ref v pass by value
// reviewed pointers II
// reviewd ppointers with classes and structures


//ADT = Abstract Data Type:
	//Asbtract = "I Define"

// let's now review data structures

struct node // each linkedlist element is called a node
{
	string data;
	node * next; //a node, structure, that will point to the following node in the linkedlist
};

int main() // pointers review & passing by value v reference
{
	node * head = new node; // dynamically allocate the head of the linked list which is made of nodes
}

