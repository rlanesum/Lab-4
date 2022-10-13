#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream inFile;
string temperature;

int answer;
int x;
int i;

char star = '*';
char line = '|';


void getValues();
void printScale();
void star_Output();
void star2_Output();

int main()
{

	printScale();
	getValues();

	inFile.close();
	return 0;
}
// void function is used to get the temperature values from the input file and output them
void getValues() 
{
	inFile.open("hourlyTemp.dat");
	if (!inFile.is_open())
	{
		cout << "Error, Input File is not opening.";
	}

	while (inFile.good()) 
	{
		inFile >> x;
		star_Output();
		star2_Output();
	}

}
// void funcion is used to print the first row with a temperature scale from -30 till 120 in 30 degree intervals
void printScale() 
{
	cout << setw(7) << "-30";
	cout << setw(10) << "0";
	cout << setw(10) << "30";
	cout << setw(10) << "60";
	cout << setw(10) << "90";
	cout << setw(10) << "120" << endl;
}

// Function is used to print all corresponding stars of the positive temperature values
void star_Output() 
{
	// divide by three to know how many stars are printed
	answer = x / 3;

	// if statement to ensure the temperature values are more than 0
	if (x > 0) 
	{	
		//output the temperature value
		cout <<  x;
		
		// If statement to distinguish values over 99 with three characters, making them a character closer to where line is printed so "setw" is one less than the normal
		if (x > 99)
		{
			cout << setw(14) << line;
		}
		else 
		{
			// represents the normal width to where the line is printed for positive numbers
			cout << setw(15) << line;
		}

		//set the answer variable as the loop limit to print a specific number of variables
		for (i = 0; i < answer; i++) 	
		{
			cout << star;
		}
		cout << endl;
	}
}

// Function is used to print all corresponding stars of the negative temperature values
void star2_Output() 
{
	// to ensure the stars are printed we need positive values for the answer variable so we multiply the negative temperatures by -1 before we divide them
	int y = x * -1;
	// divide by three to know how many stars are printed
	answer = y / 3;

	//if statement to ensure the temperature values are less than 0
	if (x < 0)
	{
		// output the tempearature value
		cout << x;

		// 10 maximum stars are possible as the scale's lowest point in -30, for every star that is not outputted, a space is outputted.
		int spaces = 10 - answer;

		// If statement to distinguish values less than -9  with three characters(2 numbers and the negative sign), making them a character closer to where line is printed so "setw" is one less than the normal
		if (x < -9)
		{
			cout << setw(4);
		}
		else 
		{
			// represents the normal width to where the line is printed for negative numbers
			cout << setw(5);
		}
		// loop to print the certain number of spaces
		for (i = 0; i < spaces; i++) 
		{
			cout << " ";
		}
		// loop to print the stars in the remainder of the 10 possible spaces
		for (i = 0; i < answer; i++) 
		{
			cout << star;
		}
		cout << line << endl;
	}
}



