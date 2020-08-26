// Workshop 1 - Linkage, Storage Duration, Namespaces,
// and OS Interface
// w1.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion:11/9/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include "process.h"

using namespace std;

// TODO: Declare (without defining) the global variable
// you have defined in CString.cpp

int main(int argc, char* argv[])
{
	extern int STORED;

	cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << ' ';
	}
	if (argc < 2)
	{
		cout << "\nInsufficient number of arguments\n";
		return 1;
	}

	// TODO: Add code here that will print out max characters
	// stored by your CString object
	
	else
	{
		cout << "Maximum number of characters stored: " << STORED << endl;
	
		for (int i = 1; i < argc; i++)
		{
			process(argv[i], cout);


		}
	}

	

	return 0;
}