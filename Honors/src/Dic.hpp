/*
 * Dic.hpp
 *
 *  Created on: Sep 16, 2019
 *      Author: shahafdan
 */

#ifndef DIC_HPP_
#define DIC_HPP_


#include <string>
#include <iostream>
#include <iomanip>
#include <set>
#include "Dic.hpp"
using namespace std;
class Dic //templatize in stage two
{
private:
	struct node
	{
		char letter;
		node * nexts = new node [26];
	};
	int wordCounter;
	node * head;
	string letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
public:
	Dic();
	void insertHelper(string word, node * curNode);
	void insert(string word); //wordCounter++;
	int getWordCounter();
	void incWordCounter();
	void remove(string word);


};



#endif /* DIC_HPP_ */
