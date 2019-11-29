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
char letters [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

Dic::Dic()
{
	head = new node;
	wordCounter = 0;
	head -> let = '_';


}


