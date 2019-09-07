/*
 * LL.hpp
 *
 *  Created on: Sep 6, 2019
 *      Author: shahafdan
 */


#ifndef LL_HPP_
#define LL_HPP_

#include <string>
#include <iomanip>
using namespace std;

class LL
{
private:
	struct LLnode
	{

		string theData;
		LLnode * fwdPtr;
	};

	LLnode * llh;
public:
	void push_front( string newData);
	void push_back( string newData);
	int list_length();
	string retrieve_front ();
	string retrieve_back ();
	void display_list();
	LL();
};


#endif /* LL_HPP_ */
