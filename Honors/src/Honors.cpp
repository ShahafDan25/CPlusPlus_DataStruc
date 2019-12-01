//============================================================================
// Name        : Honors.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <iomanip>

#include "Dic.hpp"


int main()
{
	cout << "Welcome to my honors program" << endl;
	Dic d; //create dictionary
	int answer; // create operation slecetion index
	cout<<  "-------------------------- \n Select: \n 1 to insert word \n 2 to remove a word \n 3 to check if a word is in the dictionary\n 9 to quit the program \n-------------------------- " << endl;
	cin >> answer;
	string word;
	string decision;
	while(answer != 9)
	{
		if(answer == 1)
		{
			cout << "Insert Word: ";
			cin >> word;
			d.insertWord(word);
		}
		else if(answer == 2)
		{
			cout << "remove word: ";
			cin >>  word;
			//call function to remove a word
			d.remove(word);
		}
		else if(answer == 3)
		{
			cout << "Check for: ";
			cin >>  word;
			if(d.check(word)) cout << "Word Found!" << endl;
			else
			{
				cout << "Not found in dictionary, would you like to insert it to the dictionary? (y/n)  ";
				cin >> decision;
				if(decision == "y") d.insertWord(word);
				else if(decision == "n")  cout << "Okay, going back to menu" << endl;
				else cout << "Invalid, going back to menu" << endl;
			}
		}
		else
		{
			cout << "Invalid Action Index. ";
		}
		cout << " >> Choose Action Again: ";
		cin >> answer;
	}
	cout << "Goodbye!" << endl;
	// TODO: code display all words

	return 0;
}
