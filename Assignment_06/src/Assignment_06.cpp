//============================================================================
// Name        : Assignment_06.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Q.hpp"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int size, clock, ticks, count;
	server * s = new server;
	count = size - 1;
	cout << "Please enter Queue size" << endl;
	cin >>  size;
	Q(size);

	s -> busy = false;
	clock = 0;
	while(clock < ticks)
	{
		if(!s->busy)
		{
			if(count > 0)
			{

				count --;
				s -> busy = true;
			}
		}

	}
	return 0;
}
