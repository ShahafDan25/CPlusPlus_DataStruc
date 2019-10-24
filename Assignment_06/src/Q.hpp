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
struct trans
{
	string id;
	int units;
};

struct server
{
	bool busy;
	int speed;
	int time;
};


class Q
{
private:
	trans * items;
	int length;
	int front;
	int tail;

public:
	Q();
	Q(int size);
	void insertQ(trans * t);
	void deleteQ();
	bool checkForTrans();
	bool checkProb(int prob);

};


#endif /* Q_HPP_ */
