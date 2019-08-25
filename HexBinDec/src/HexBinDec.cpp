//============================================================================
// Name        : HexBinDec.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Convert from one base to another" << endl;
	string fromBase = "";
	char HexBase [16] = {'0', '1', '2', '3' ,'4','5','6','7','8','9','A','B','C','D','E','F'};
	bool badValue = false;
	bool rightBase = false;
	while(!rightBase)
	{
		cout << "Select the base you would like to convert from (Hex or Bin) to Decimal" << endl;
		cin >> fromBase;
		if(fromBase == "Hex" || fromBase == "Bin")
		{
			rightBase = true;
		}
	}

	string value = "";
	cout << "enter your value " << endl;
	cin >>  value;
	int length = 0;
	bool exists;
	//char baseValue[length];
	while (badValue) //check if the input value is valid
	{
		//first convert to character array from string
		length = value.size();
		char baseValue[length +1 ];
		value.copy(baseValue, length +1 );
		baseValue[length] = '\0';

		//check for bin or hex
		if(fromBase == "Hex")
		{
			for( int i = 0; i < sizeof(baseValue) ; i++) //traverse through the characters of the entered value
			{
				for(int j = 0; j < sizeof(HexBase); j++)
				{
					exists = find(begin(HexBase), end(HexBase), baseValue[i]);
					if(!exists)
					{
						break;
					}

				}
				if(exists)
				{
					badValue = false;
					break;
				}
			}
		}
		else if(fromBase == "Bin")
		{
			for(int i = 0; i < sizeof(baseValue); i++)
			{
				if(baseValue[i] != '1' || baseValue[i] != '0')
				{
					badValue = true;
					exists = true;
				}
			}
			if(exists)
			{
				badValue = false;
				break;
			}
		}
	}


	for(int i = 0 ; i < sizeof(baseValue); i++)
	{
		cout << baseValue[i] << endl;
	}




	return 0;
}
