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


// hex array
	char hexValues[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
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
			bool notHex = false;
			cout << "let's convert hexa to decimal" << endl;
			cout << "enter you hexaDecimal value" << endl;
			string value;
			cin >> value;
			if(value.size() > 4)
			{
				cout << "value too long, going back to menu" << endl;
			}
			else // meaning value is in the right size
			{
				//first convert the string to an array of characters
				int length = value.size();
				char valueCarr[length + 1];
				value.copy (valueCarr, length + 1);
				valueCarr[length] = '\0';

				// check for character validity now
				for(int i = 0; i < sizeof(valueCarr); i++) //traverse trough characters of the string value
				{
					for(int j = 0; j < sizeof(hexValues); j++) //traverse through arrays of hex values
					{
						if(valueCarr[i] == hexValues[j])
						{
							notHex = false;
						}
						else
						{
							notHex = true;
							break;
						} //end of boolean else
					}// end of inner for
					if(notHex)
					{
						break;
					} //end of if
				}// end of outer for

				if(notHex)
				{
					cout << "Your hexaDecimal Value is invalid, going back to menu" << endl;

				}
				else //calling function
				{
					hexToDecimal(value);
				}
			} // end of else = end of assuming array in the right size


		}
		else //else, if the number enteres is not 1,2,3,4 or 9
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
