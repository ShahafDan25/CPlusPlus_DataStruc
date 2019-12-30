/*
 * Dic.cpp
 *
 *  Created on: Sep 16, 2019
 *      Author: shahafdan
 */
#include <string>
#include <iomanip>
#include <iostream>
#include <set>
using namespace std;
#include "Dic.hpp"

/// GLOABL ARRAY AS A REFERENCE
char lettersIndex [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

Dic::Dic()
{
	head = new node;
	wordCounter = 0;
	head -> let = '_';
	wordCounter = 0;
}


int Dic::letterIndexFinder(char letter)
{
	//using binary search in the array, this function will return the specific index number of the letter from the global array
	// we already know the length is 26 (hard coded) because there are only 26 letters in the alphabetical english

	///LATER: improve to be binary serach to imporve upon speed
	//for now: linear search
	for(int i = 0; i < 26; i++)
	{
		if(lettersIndex[i] == letter)
		{
			return i ;
			break;
		}
	}
	return -2; //will return -2 if the letter is not found
}


void Dic::insertWord(string word)
{
	//The function will return true if the word already exists
	string def;


	if(word.length() < 2) //base case
	{
		cout << word << endl;
		cout << "ERROR: please enter a word with at least two letters!" << endl;
		return;
	}
	if(check(word))
	{
		cout << "ERROR: Word already exists" << endl;
		return;
	}
	node * trav = new node;
	trav = head;
	for(int i = 0; i < word.length(); i++)// letter by letter, insert into the dictionary
	{

		// TODO: Find solution to inserting through, and then throughout (for example)
		// Another example: play, player
		int p = letterIndexFinder(word[i]); // the index of the word (be positive if the letter exists)

		if(p >= 0)
		{
			if(i == word.length() - 1)
			{
				cout << "Enter the definition of the word (be laconic)" << endl;
				cin.ignore();
				getline(cin, def);
			}
			node * newNode = new node;
			newNode -> let = word[i];
			if(trav -> nextLetter[p] != nullptr)
			{
				trav = trav -> nextLetter[p];
				if(i == word.length() - 1) trav -> definition = def; //the last letter will contain the definiton}
			}
			else // insert the word to a different direction
			{
				if(i == word.length() - 1) newNode -> definition = def; //the last letter will contain the definiton}
				trav -> nextLetter[p] = newNode;
				trav = trav -> nextLetter[p];
			}
			if( i == word.length() - 1)cout << "word inserted!" << endl;
			//delete newNode; //delete dynamically allocated node;
		}
		else //word had a character that is not in the english alphabet
		{
			cout << "WORD IS INVALID: ENGLISH LOWERCASE LETTERS ONLY" << endl;
			cout << p << endl;
			break;
		}
	} //end for
	//delete trav; //delete dynamically allocated node;
	wordCounter++;
	return;
}

bool Dic::check(string word) //recursively
{
	node * trav = new node;
	trav = head; //-> nextLetter [letterIndexFinder(word[0])];
	return checkHelper(word.length(), word, 0, trav); //call helper recursively
	//delete trav; // delete dynamically allocated node
}

bool Dic::checkHelper(int size, string word, int i, node * trav)
{
	if(i == size)
	{
		if((trav -> definition).length() == 0)return false;
		cout << "Definition: " << trav -> definition << endl;
		return true; // got to the end of the board //base case
	}
	else
	{
		int p = letterIndexFinder(word[i]);
		trav = trav -> nextLetter[p];
		if(trav != nullptr) return checkHelper(size, word, i + 1, trav);
		else return false;
	}
}


bool Dic::makeSureClean(node * check)
{
	for(int i = 0; i < 26; i++)
	{
		if(check -> nextLetter[i] != nullptr) return false;
	}
	return true;
}
void Dic::remove(string word) //non recursive
{
	if(word.length() < 2)
	{
		cout << "WORD TOO SHORT" << endl;
		return;
	}
	if(!check(word))
	{
		cout << "ERROR: word does not appear to be in the dictionary" << endl; //Should I ask the user if they would like to insert that word that does not appear? Because they are removing it anyways
		return;
	}
	int j;
	node * trav = new node;
	for(int i = word.length() - 1; i >= 0; i--) //reverse because we are going to delete letter by letter; (noder by noder)
	{
		trav = head; // set to the dictionary's root (head), then go to the last one according to the word
		for(j = 0; j <= i; j++)
		{
			trav = trav -> nextLetter[letterIndexFinder(word[j])]; //get to the right node;
		}
		if(makeSureClean(trav))
		{
			trav = nullptr;
			delete trav;
			break;
		}
		else
		{
			trav -> definition = "";
			break;
		}
	}
	cout << "'" << word << "'" << " has been removed from our dictionary!" << endl;
	wordCounter--;
	return;
}

int Dic::getAmountWords()
{
	if(makeSureClean(head)) return 0;
	else return wordCounter;
}
