

// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include<iostream>
#include"CString.h"
#include<cstring>

using namespace std;

//const int STORED= 3; //global variable
int STORED= w1:: NO_CHARACTERS;

namespace w1 {

	CString::CString(const char*ch) {

		if(ch[0] == '\0'){ //if this is empty
		
			PRESERVE[0] = '\0'; // zero characters inside this array
		}

		else {
			strncpy(PRESERVE, ch, NO_CHARACTERS);
			PRESERVE[NO_CHARACTERS] = '\0';
		}
	}

	void CString::display(ostream& os) const {

		os << PRESERVE << endl;

	}

	ostream& operator <<(ostream& os, const CString& rhs) {

		static int counter = 0;
		os << counter << ": " << endl;
		rhs.display(os); // sending the counter to the display function thats present in the CString class
		counter++;
		return os;
	}

}


