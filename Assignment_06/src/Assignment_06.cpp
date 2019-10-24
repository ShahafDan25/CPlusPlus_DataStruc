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
#include <string>
#include <set>
#include <cstdlib>
using namespace std;


int main()
{

	int size, clock, ticks, newTransProb, endTransProb, tg, ts, tp;
	bool transStarted = false;
	cout << "Please enter Queue size" << endl;
	cin >>  size;
	Q q(size);

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
	string id;
	int u;
	while(clock < ticks)
	{
		// ------ ARRIVAL -------
		if(q.checkProb(newTransProb))
		{
			cout << "Transaction will be created!" << endl;
			cout << "Enter Transaction's id" << endl;
			cin >> id;
			cout << "Enter the transaction's amount of units" << endl;
			cin >> u;
			q.insertQ(id, u); //insert the transaction in the queue function
			tg++; //counter of how many transactions have been generateds
		}
		else cout << "A transaction should not be generated" << endl;


		// ------ PROCESSING -----
		if(!transStarted)
		{
			if(q.checkForTrans()) //if there is a transaction in the queue
			{
				//what does he mean by start transaction?
				q.deleteQ();
				transStarted = true;
				ts++; //transactions started incerement
			}
		}
		// ------ LEAVING ------
		if(transStarted)
		{
			if(q.checkProb(endTransProb))
			{
				transStarted = false;
				tp++;
			}
		}
		clock++;
	}


	cout << endl << "-----  FINAL REPORT -----"<< endl << endl;
	cout << "Clock Ticks: " << ticks << endl;
	cout<< " Transactions Generated: " << tg << endl;
	cout << " Transaction Processed: " << tp << endl;
	cout << "Transactions Started: " << ts << endl;
	cout << "Transaction Left In Queue: " << size - tg - tp << endl;
	return 0;
}
