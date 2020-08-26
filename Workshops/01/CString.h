// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include<iostream>

using namespace std;



namespace w1 {

	const int NO_CHARACTERS = 3;

	class CString {

		char PRESERVE[NO_CHARACTERS + 1];
		
	public:
		CString(const char*);
		void display(ostream& os) const;

	};

	ostream& operator <<(ostream& os, CString& rhs);

}



#endif //


