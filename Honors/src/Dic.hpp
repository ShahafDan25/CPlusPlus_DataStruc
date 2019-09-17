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
	struct Node
	{
		char letter;
		Node * next;
	};
	int wordCounter;
	Node * header;
public:
	void insert(string word); //wordCounter++;
	int getWordCounter();
	void setWordCounter();
	void remove(string word);


};



#endif /* DIC_HPP_ */
