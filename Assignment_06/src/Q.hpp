/*
 * Q.hpp
 *
 *  Created on: Oct 20, 2019
 *      Author: shahafdan
 */

#ifndef Q_HPP_
#define Q_HPP_


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
	trans * elems;
	int length;
public:
	Q();
	Q(int size);

};


#endif /* Q_HPP_ */
