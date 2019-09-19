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
#include <set>
using namespace std;
template <class dataType>
class LL
{
private:
	struct LLnode
	{

		dataType theData;
		LLnode * fwdPtr;
	};

	LLnode * llh;
public:
	void push_front( dataType newData);
	void push_back( dataType newData);
	int list_length();
	dataType retrieve_front ();
	dataType retrieve_back ();
	void display_list();
	LL();

	//PART 3 FUNCTIOn
	void destroy_list();
	bool search_list(dataType data);
	bool delete_node(dataType value);
};


#endif /* LL_HPP_ */
