/* Benjamin Roe
 C++ Fall 2019
 Due October 10, 2019
 Lab 4 Temperature Output

Design and write a C++ program that inputs a series of hourly temperature
from a file, and outputs a bar chart (using stars) of the temperatures for the day. The
temperature should be printed to the left of the corresponding bar, and there should be
a heading that gives the scale of the chart. The range of temperatures should be from
-30 to 120. Because it is hard to display 150 characters on the screen, you should have
each star represent a range of 3 degrees. That way, the bars will be at most 50
characters wide. Use meaningful variable names, proper indentation, and appropriate
comments. Thoroughly test the program using your own data sets. Make sure to vet the
values from the input file.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

float userInput;
float subInput;
void stars();
ifstream infile;

int main()
{
	cout << "		|-30      |0|         |30       |60       |90       |120      " << endl;
	//Line above displays the numbers along the top for the sake of formatting.
	infile.open("C:/Users/ROE26/Desktop/temperatureInput.dat"); //Opens input file.
	if (!infile)
	{
		//Response when input file cannot be found.
		cout << "Cannot locate input file.";
		return 1; //Error code for missing input file is 1.
	}

	infile >> userInput; //Priming read of the input file.

	while (infile)
		/* This "while" statement displays the number input and then calls the function that
		makes the stars display. It, together with the if statement below it also detect
		and handle failed inputs. */
	{
		cout << setw(8) << (userInput);
		stars();
		if (infile.eof())
			/*Exits the "while" statement when the end of the inputs is 
			reached but before the stream becomes invalid*/
			break;
		infile >> userInput;
	}
	if (!infile)
	{
		//Response when an input fails due to not being a number.
		cout << "An input failure has occured. The program will now terminate.";
		return 2; //Error code for a failed input is 2.
	}
	return 0; //If no errors occur then the program will exit with 0.
}

void stars()
{
	cout << "	"; //tab for formatting
	if (userInput > 120 || userInput < -30) //Response for values outside valid the range.
	{
	cout << "  Invalid | | Input";
	}
	else if (userInput >= 1.5) 
		/* Determines number of stars that must be displayed for positive input values and
		displays that many stars.*/
	{
		cout << "	  | |";
		while (userInput >= 1.5)
		{
			userInput = userInput - 3;
			cout << "*";
		}
	}
	else if (userInput <= -1.5)
		/* Determines number of stars that must be displayed for negative input values and
		displays that many stars as well as the number of spaces that must come before the stars.*/
	{
		subInput = -30 - userInput;
		while (subInput < -1.5) //Places spaces before the stars in order to format correctly.
		{
			cout << " ";
			subInput = subInput + 3;
		}
		while (userInput <= -1.5) //Places the stars for negative input values.
		{
			userInput = userInput + 3;
			cout << "*";
		}
		cout << "| |";
	}
	else if (userInput > -1.5 && userInput < 1.5) //Displays no stars for values between -1.5 and 1.5
	{
		cout << "	  | |";
	}
	cout << endl;
}