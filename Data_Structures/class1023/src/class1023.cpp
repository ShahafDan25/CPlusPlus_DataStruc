//============================================================================
// Name        : class1023.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int generateKey()
{
	//will take as specific value, and will generate a key value we
	//will use to access its location in the has table
	bool done = false;
	int a,b,c,d;
	while(!done)
	{
		a = rand();
		b = rand();
		c = rand();
		//d = rand();

		d = abs(a * b * c);
		d = d % 999999999;
		if(d > 100000000 && d < 900000000) done = true;
	}
	cout << "generated key: " << d << endl;
	return d;
}

int hashFunction(int key)
{
	int r = key % 100;
	return r;
}

int main()
{
	cout << "CLASS Of 1023 ---- HASH TABLES!! " << endl << endl;

	int hashTable[100]; //this will represent our hash table
	for(int i = 0 ; i < 100; i++)
	{
		int key= generateKey();
		int htentry = hashFunction(key);
		cout <<"key " << key << " hasehd to " << htentry << endl;
		hashTable[htentry] = key;
	}
	return 0;
}
