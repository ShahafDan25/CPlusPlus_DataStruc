//============================================================================
// Name        : HexBinDec.cpp
// Author      : ShahafDan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<iomanip>
#include <cmath>
using namespace std;

// hex array
	char hexValues[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


// have different functions for different actions;
	void decimalToBinary(int dec) //works!
	{
		cout << endl << "value entered in valid" << endl;
		string bin = "";
		string revBin = "";
		string oldDec = to_string(dec);
		int r;
		while(dec != 0)
		{
			r = dec % 2;
			dec = dec / 2;
			if(r == 1)
			{
				bin += "1";
			}
			else
			{
				bin += "0";
			}
		}// end of while

		int length = bin.size();
		char binCarr[length + 1];
		bin.copy (binCarr, length + 1);
		binCarr[length] = '\0';

		for(int y = sizeof(binCarr)-1; y >= 0; y--)
		{
			revBin += binCarr[y];
		}


		cout << "Decimal " << oldDec << " convert into binary: " <<  revBin << endl;
		cout << endl;//FLIPPED
		return;
	}

	void binaryToDecimal(string bin) //works!
	{
		//convert the string first to an array
		int length = bin.size();
		char binCarr[length + 1];
		bin.copy (binCarr, length + 1);
		binCarr[length] = '\0';
		cout << binCarr << endl;
		int dec = 0;
		int count = 0;
		for(int i = sizeof(binCarr) - 2; i >= 0; i--)
		{
			dec += (binCarr[i] - '0') * (pow(2, count));
			count ++;
		}

		cout << "Binary " << bin << " converted to decimal is: " <<  to_string(dec) << endl;
				return;
	}

	void decimalToHex(int dec) //works!
	{
		string hex = "";
		string revHex = "";
		string oldDec = to_string(dec);
		int r;
		while(dec != 0)
		{
			r = dec % 16;
			dec = dec / 16;
			hex += hexValues[r];
		}

		//REVERSES HEX STRING
			//1. convert to char array
			//2. for loops to traverse backwards
			//3. build revHex string;
		int length = hex.size();
		char hexCarr[length + 1];
		hex.copy (hexCarr, length + 1);
		hexCarr[length] = '\0';

		for(int y = sizeof(hexCarr)-1; y >= 0; y--)
		{
			revHex += hexCarr[y];
		}

		//PRINT
		cout << "decimal " << oldDec <<  " to hex is " << revHex << endl;
		return;
	}

	void hexToDecimal(string hex) //works
	{
		int dec = 0;
		int count = 0;
		//convert the hex string to a char array
		int length = hex.size();
		char hexCarr[length +1];
		hex.copy (hexCarr, length + 1);
		hexCarr[length] = '\0';

		int index = 0;

		for(int i = sizeof(hexCarr) - 2; i >= 0; i--)
		{
			//check for index value in hex values array
			for( int h = 0; h < sizeof(hexValues); h++)
			{
				if(hexValues[h] == hexCarr[i])
				{
					index = h;
					break; //break the loop
				}
			}

			dec += (index) * (pow(16, count));
			count ++;
		}
		cout << "hex: " << hex << " to decimal is: " << dec << endl;
		return;
	}


// main function
int main()
{
	cout << "Choose From Menu" << endl;
	cout << "1) Decimal To Binary \n 2) Binary To Decimal \n 3) Decimal to Hex \n 4) Hex to Decimal \n 9) Exit Program" << endl;
	string answer = "";
	cin >> answer;
	while(answer != "9")
	{
		if(answer == "1")
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
				decimalToBinary(value);
			}
		}// end if scenario 1
		else if(answer == "2")
		{
			bool invalid = false; //coming from the assumption that the value is valid
			cout << "Let's convert binary to decimal" << endl;
			cout << "enter your binary number" << endl;
			string value;
			cin >> value;
			if(value.size() > 8)
			{
				cout << "you entered a binary number longer than 8 bits, going back to menu" << endl;
			} // end if length
			else // if size of string is ok
			{
				//first convert to array of characters
				int length = value.size();
				char valueCarr[length + 1];
				value.copy (valueCarr, length + 1);
				valueCarr[length] = '\0';

				//// then check for vlaidity
				for(int i = 0; i < sizeof(valueCarr); i++) //checking for validity
				{
					if(valueCarr[i] > '1' )
					{
						invalid = true;
					}
				}//end for
				if(!invalid) //call function, bin is valid
				{
					binaryToDecimal(value);
				}
				else
				{
					cout << "value is invalid, going back to menu" << endl;
				}
			}
		}
		else if(answer == "3")
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
				decimalToHex(value);
			}// end else
		}
		else if(answer == "4")
		{
			bool invalid = true; //coming from the assumption the the value is  invalid
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
						if(valueCarr[i] == hexValues[j]) // MAY NOT BE RIGHT - IF STATEMENT LOCATION MAY NOT BE RIGHT
						{
							invalid = false;
						}// end of check for validity inner if statement

					}// end of inner for
					if(invalid ) // if still invalid, break the loop
					{
						break;
					} //end of if
				}// end of outer for

				if(invalid)
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
		cout << endl << "------------------------" << endl;
		cout << "1) Decimal To Binary \n 2) Binary To Decimal \n 3) Decimal to Hex \n 4) Hex to Decimal \n 9) Exit Program" << endl;
		cin >> answer;
	} // end of while / program

	cout << "You exited the program, goodbye!" << endl;

	return 0;
}// end of main

