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

Dic::Dic()
{
	head = new node;
	wordCounter = 0;
	head -> nexts = nullptr;
	head -> letter = '_';


}
void Dic::insertHelper(string word, node * CurNode)
{
	wordCounter++;

}
void Dic::insert(string word)
{
	int count = 0;
	cout << "inserting " << word << "into the dictionary tree" << endl;
	string toinsert = "_" + word;
}

void Dic::remove(string word)
{

}

int Dic::getWordCounter()
{
	return wordCounter;
}

void Dic::incWordCounter()
{
	wordCounter++;
}

