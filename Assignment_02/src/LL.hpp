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
	void push_front( const dataType & newData);
	void push_back( const dataType & newData);
	int list_length();
	string retrieve_front ();
	string retrieve_back ();
	void display_list();
	LL();

	//PART 3 FUNCTIOn
	void destroy_list();
	bool search_list(const dataType & data);
	bool delete_node(const dataType & value);
};


#endif /* LL_HPP_ */
