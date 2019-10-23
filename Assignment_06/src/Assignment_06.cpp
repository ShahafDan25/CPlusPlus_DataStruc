//============================================================================
// Name        : Assignment_06.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Q.hpp"
#include <iostream>
#include <iomanip>
#include <time>
using namespace std;
bool checkProb (int prob)
{
	//generate a random number
	//check for validity
	int rand = rand() % 100 + 1;
	if(rand() <= prob) return true;
	else return false;
}

int main()
{
	int size, clock, ticks, newTransProb, endTransProb;
	cout << "Please enter Queue size" << endl;
	cin >>  size;
	Q * q = new Q(size);

	cout << "How many clock ticks are we looking at?" << endl;
	cin >> ticks;

	cout << "what is the success probability? number between 1 and 100" << endl;
	cin >>  newTransProb;
	while(newTransProb < 1 || newTransProb > 100)
	{
		cout << "Invalid, enter probability again (percentage)" << endl;
		cin >> newTransProb;
	}

	cout << "what is the failure probability? number between 1 and 100" << endl;
	cin >>  endTransProb;
	while(endTransProb < 1 || endTransProb > 100)
	{
		cout << "Invalid, enter probability again (percentage)" << endl;
		cin >> endTransProb;
	}
	clock = 0;
	while(clock < ticks)
	{
		// ------ ARRIVAL -------

		// ------ PROCESSING -----
		// ------ LEAVING ------
		clock++;
	}
	return 0;
}
