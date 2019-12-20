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

	//we want now to define the data in the linked list element to "shahaf dan"
	head -> data = "shahaf dan"; // by using the operator -> we can refer to the member of the struct
	// the data member of type string in the first member of the linked list (called head) will contain "shahaf dan"

	//now we want to end the linked list. We do this by defining the pointer to the end and assigning the value of it to null
	head -> next = nullptr; // when assigning a null to a pointer we assign a nullptr
}

