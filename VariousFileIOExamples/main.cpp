//*********************************************************************
// File name:			main.cpp
// Author:				chadd williams
// Date:					Nov 29, 2022
// Class:					CS 150-02
// Assignment:		File IO Examples
// Purpose:				Clarify how to handle the File input correctly
// Hours Worked:	0.1
//*********************************************************************

#include <iostream>
#include <fstream>

using namespace std;

int main () {

	const string SENTINEL = "DONE";
	string fileLine;
	char fileChar;
	int counter;
	ifstream inFile;

	inFile.open ("data.txt");

	// using a sentinel value with >> 
	inFile >> fileLine;
	counter = 1;
	while (SENTINEL != fileLine) {
		cout << "Line " << counter << ": " << fileLine << endl;
		counter++;
		inFile >> fileLine;
	}

	// reset the file to read from the start, position 0
	inFile.seekg (0);

	// using only >>
	counter = 1;

	// inFile >> fileLine returns false if there is no
	// data to read!
	// NOTE: prints sentinel value!
	while (inFile >> fileLine) {
		cout << ">Line " << counter << ": " << fileLine << endl;
		counter++;
	}


	// calling clear is necessary BEFORE using .get()
	inFile.clear ();
	// reset the file to read from the start, position 0
	inFile.seekg (0);

	// using .get()
	counter = 0;
	fileChar = inFile.get ();
	while (!inFile.eof ()) {
		cout << "char " << counter << ": |" << fileChar << "|" << endl;
		counter++;
		fileChar = inFile.get ();
	}

	// calling clear is necessary BEFORE using .get()
	inFile.clear ();
	// reset the file to read from the start, position 0
	inFile.seekg (0);

	// using .get(ch)
	counter = 0;
	inFile.get (fileChar);
	while (!inFile.eof ()) {
		cout << ">char " << counter << ": |" << fileChar << "|" << endl;
		counter++;
		inFile.get (fileChar);
	}

	inFile.close ();

	return EXIT_SUCCESS;
}