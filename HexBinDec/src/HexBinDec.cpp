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

// have different functions for different actions;
	string decimalToBinary(string dec)
	{
		string bin;

		return bin;
	}

	string binaryToDecimal(string bin)
	{
		string dec;

		return dec;
	}

	string decimalToHex(string dec)
	{
		string hex;

		return hex;
	}

	string hexToDecimal(string hex)
	{
		string dec;

		return dec;
	}
// main function
int main()
{
	cout << "Choose From Menu" << endl;
	cout << "1) Decimal To Binary \n 2) Binary To Decimal \n 3) Decimal to Hex \n 4) Hex to Decimal \n 9) Exit Program" << endl;
	int answer = 0;
	cin >> answer;
	while(answer != 9)
	{
		if(answer == 1)
		{
			cout << "let's convert decimal to binary" << endl;
			cout << "Enter a decimal number please" << endl;
			int value;
			cin >> value;
			if(value < 0)
			{
				cout << "you entered a negative number, going back to menu" << endl;
			}
			else
			{
				decimalToBinary(to_string(value));
			}
		}// end if scenario 1
		else if(answer == 2)
		{
			bool notBin = false;
			cout << "Let's convert binary to decimal" << endl;
			cout << "enter your binary number" << endl;
			string value;
			cin >> value;
			if(value.size() > 8)
			{
				cout << "you entered a binary number longer than 8 bits, going back to menu" << endl;
			} // end if length
			else
			{
				for(int i = 1; i < value.size(); i++) //checking for validity
				{
					if(!(value.substr(i-1,1) == "1" || value.substr(i-1,i) == "0"))
					{
						cout << "Binary number not valid" << endl;
						notBin = true;
						break;
					} // end if in for
				}//end for
				if(!notBin) //call function, bin is valid
				{
					binaryToDecimal(value);
				}
			}
		}
		else if(answer == 3)
		{
			cout << "let's convert decimal to hexa" << endl;
			cout << "enter your decimal number" << endl;
			int value;
			cin >> value;
			if(value < 0)
			{
				cout << "value is negative and therefore invalid; Going back to menu" << endl;
			}//end conditioning if
			else
			{
				//call function
				decimalToHex(to_string(value));
			}// end else
		}
		else if(answer == 4)
		{
			cout << "let's convert hexa to decimal" << endl;
			cout << "enter you hexaDecimal value" << endl;
			string value;
			cin >> value;
			if(value.size() > 4)
			{
				cout << "value too long, going back to menu" << endl;
			}
			else // meaning value is in the right length
			{

			}
			//1. check for validity through travesring two arrays
			//2. check for 4 digits

		}
		else
		{
			cout << "your answer is not valid, enter again" << endl;
		}


		// represent the menu again
		cout << "1) Decimal To Binary \n 2) Binary To Decimal \n 3) Decimal to Hex \n 4) Hex to Decimal \n 9) Exit Program" << endl;
		cin >> answer;
	} // end of while / program

	cout << "You exited the program, goodbye!" << endl;

	return 0;
}// end of main
