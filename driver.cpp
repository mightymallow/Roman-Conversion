//Gergely Sajdik A00976672
//Assignment #2
//Version 1.0
//May 7, 2018

#include <iostream>
#include <cctype>
using namespace std;

int main() {

	char c; //char field to store each numeral for switch
	int oldNumericValue; //previous numeral value to use to compare to current
	int numericValue; //current numeral value entered
	int total = 0; //keeps track of total value of numerals
	int counter = 1; //keeps track of loop iterations
	bool foundError = false; //tracks if an error was found

	//starting output message
	cout << "10 Roman numeral values will be input and converted into\ntheir equivalent Hindu-Arabic numberic values.";
	cout << "\n\nInput Roman numeral # " << counter++ << ": ";

	//while loop to complete 10 iterations
	while (counter <= 11) {

		//reset all values at start of each iteration
		total = 0;
		oldNumericValue = 0;
		numericValue = 0;
		foundError = false;

		//check to see if end of line every single character or if there is an error
		while (((c = cin.get()) != '\n') && foundError == false) {
	
			c = toupper(c); //capitalize the letter

			switch (c) //switch function to assign digit to roman numeral
			{
			case 'I': numericValue = 1;
				cout << "I";
				break;
			case 'V': numericValue = 5;
				cout << "V";
				break;
			case 'X': numericValue = 10;
				cout << "X";
				break;
			case 'L': numericValue = 50;
				cout << "L";
				break;
			case 'C': numericValue = 100;
				cout << "C";
				break;
			case 'D': numericValue = 500;
				cout << "D";
				break;
			case 'M': numericValue = 1000;
				cout << "M";
				break;
			default:
				cout << c << " Error - last character was not valid!!!";
				foundError = true;
				break;
			}

			//mathematical calculation comparing previous and current numeral
			if (foundError == false) {
				if (numericValue <= oldNumericValue) {
					total += numericValue;
					oldNumericValue = numericValue;
				}
				else if (numericValue > oldNumericValue) {
					total = total + (numericValue - 2 * oldNumericValue);
					oldNumericValue = numericValue;
				}
			}
			else {
				cin.ignore(1000, '\n'); //to stop reading once an error is found and skip to the end of the line
			}
		}
		
		//displays total if no errors found in the entered numerals
		if (foundError == false) {
			cout << " = " << total;
		}

		//displays output message for start of next loop or ending message
		if (counter <= 10 && foundError == false) {
			cout << "\n\nInput Roman numeral # " << counter++ << ": ";
		} else if (counter <= 10 && foundError == true) {
			cout << "\nInput Roman numeral # " << counter++ << ": ";
		} else {
			counter++;
			cout << "\n\nTHAT'S ALL FOLKS :)\n\n";
		}
	}
	system("pause");
}