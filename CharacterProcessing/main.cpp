//*********************************************************************
// File name:			main.cpp
// Author:				chadd williams
// Date:					Nov 15, 2022
// Class:					CS 150-02
// Assignment:		In Class Examples
// Purpose:				Character Processing
// Hours Worked:	0.1
//*********************************************************************

#include <iostream>
#include <fstream>

using namespace std;

int getKey (char key[], int keyMax);
int countCharsInFile (const char filename[]);

//*********************************************************************
// Function:		main
//
// Description: Demonstrate reading a character at a time
// 
// Parameters:	None
//
// Returned:		EXIT_SUCCESS
//*********************************************************************
int main ()
{
	const int SIZE = 10;
	const char filename[] = "data.txt";
	char array[SIZE];

	cout << countCharsInFile (filename) << endl;

	// cout << getKey (array, SIZE);

	return EXIT_SUCCESS;
}

//*********************************************************************
// Function:		countCharsInFile
//
// Description: count the non-whitespace characters in a file
// 
// Parameters:	filename - the name of the file
//
// Returned:		number of characters read 
//*********************************************************************
int countCharsInFile (const char filename[]) {
	char ch;
	int count = 0;
	ifstream inFile;

	inFile.open (filename);
	if (! inFile.fail ())
	{
		inFile.get (ch);
		while (!inFile.eof ()) {
			count++;
			/*if (!isspace (ch))
			{
				count++;
			}*/
			inFile.get (ch);
		}
	}

	inFile.close ();

	return count;
}

//*********************************************************************
// Function:		getKey
//
// Description: read in up to keyMax characters from the given array.
// 
// Parameters:	None
//
// Returned:		number of characters read or -1 if the key is too big
//*********************************************************************

int getKey (char key[], int keyMax)
{
	int retVal = -1;
	int index = 0;
	char inputChar;
	
	// put a NULL at the beginning of the array
	// just in case there is no input
	key[index] = '\0';
	
	// read a character
	cin.get (inputChar);

	// loop while we have not see a newline AND
	// the index has not gone past the end of the array
	while ('\n' != inputChar && index < keyMax) {
		// copy the character into the array
		key[index] = inputChar;
		index++;

		// get the new character
		cin.get (inputChar);
	}

	// if index == keyMax we read too many chars to
	// add a \0
	if (index != keyMax)
	{
		key[index] = '\0';
		retVal = index;
	}

	return retVal;
}
