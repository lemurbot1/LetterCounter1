// ConstitutionVowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

/*This code is designed to count the number of select letters in the United States Constitution

Intro to main part of the program
NOTE: I used a portion of the sample program you provided in the assignment module on Canvas.*/
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Error with input args.." << endl;
		return 1;
	}

	// For debugging purposes only
	for (int I = 0; I < argc; I++)
	{
		cout << I << ":" << argv[I] << endl;
	}

	// Opens file Constitution.txt that will be analyzed for number of vowels.
	ifstream myFile;
	myFile.open(argv[1]);
	// If the txt file doesn't open for whatever reason, the following error message will print.
	if (!myFile)
	{
		cout << "Error opening file \"Constitution.txt\"" << endl;
		return -1;
	}

	// Title of entire program.
	cout << setw(58) << setfill('*') << "" << endl;
	cout << setw(12) << setfill('*') << "";
	cout << "Welcome to my Letter Count Program";
	cout << setw(12) << setfill('*') << "" << endl;
	cout << setw(58) << setfill('*') << "" << endl;

	cout << endl;

	// Indicates to user what the code is doing, which at this point is counting out all relevant letters in Constitution.txt.
	cout << "Analyzing file \'Constitution.txt\'..." << endl;

	cout << endl;

	// Declares all local variables besides ifstream, which is declared above.
	/* All variables for specfic letters (a, b, e, i, k, o, u, z) and counter(xIndex) are initialized to 0 so as to have a starting off point
	before continuously adding to each of them. */
	char x;
	int a = 0, b = 0, e = 0, i = 0, k = 0, o = 0, u = 0, z = 0;
	int totVariable;
	int xIndex = 0;

	// While loop to act as a counter while the code analyzes each character of the txt for vowels and counts it out.
	// The while loop is set to end when the end of the file is reached.
	while (!myFile.eof() && myFile >> x)
	{
		// A switch structure is nested into the while loop. Each part is designed to add 1 to the designated vowel variable as it encounters the vowel it represents.
		switch (x)
		{
			// Both upper and lower case vowels are counted.
		case 'a':
		case 'A':
			a++; // Counter used for all vowels.
			//a = a + 1; This is how I counted the vowel variables initially.
			break;
		// New letter 1
		case 'b':
		case 'B':
			b++;
			break;
		case 'e':
		case 'E':
			e++;
			//e = e + 1;
			break;
		case 'i':
		case 'I':
			i++;
			//i = i + 1;
			break;
		// New letter 2
		case 'k':
		case 'K':
			k++;
			break;
		case 'o':
		case 'O':
			o++;
			//o = o + 1;
			break;
		case 'u':
		case 'U':
			u++;
			//u = u + 1;
			break;
		// New letter 3
		case 'z':
		case 'Z':
			z++;
			break;
		default:
			xIndex++; // If the character in the file being analyzed does not match any of the above , the counter is advanced to the next character to be analyzed.
		}

		xIndex++; // Outer loop advances counter so that the program may move on to the next character in the file.
	}

	totVariable = a + b + e + i + k + o + u + z; // Finds sum of all letters.

	// Prints out number of each relevant letter found in the file plus the total number of all letters.
	cout << "The number of A's:" << setw(30) << setfill('.') << a << endl;
	cout << "The number of B's:" << setw(30) << setfill('.') << b << endl;
	cout << "The number of E's:" << setw(30) << setfill('.') << e << endl;
	cout << "The number of I's:" << setw(30) << setfill('.') << i << endl;
	cout << "The number of K's:" << setw(30) << setfill('.') << k << endl;
	cout << "The number of O's:" << setw(30) << setfill('.') << o << endl;
	cout << "The number of U's:" << setw(30) << setfill('.') << u << endl;
	cout << "The number of Z's:" << setw(30) << setfill('.') << z << endl;
	cout << "The letter count is:" << setw(29) << setfill('.') << totVariable << endl;

	// Closes file being analyzed by program.
	myFile.close();

	// End program.
	return 0;
}
