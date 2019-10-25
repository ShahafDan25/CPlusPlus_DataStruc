/*
 * Q.hpp
 *
 *  Created on: Oct 20, 2019
 *      Author: shahafdan
 */

#ifndef Q_HPP_
#define Q_HPP_

#include <iomanip>
#include <iostream>
using namespace std;
#include <string>



//define global structures



class Q
{
private:
	struct t
	{
		string id;
		int units;
	};

	int length;
	int front;
	int tail;
	t * items;

public:
	Q();
	Q(int size);
	void insertQ(string id, int u);
	void deleteQ();
	bool checkForTrans();
	bool checkProb(int prob);
	void displayQ();

};


#endif /* Q_HPP_ */
