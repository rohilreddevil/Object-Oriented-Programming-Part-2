// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@gmail.com
// Date of completion: 12/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict {

	 enum class Letter { A_, A, B_, B, C_, C, D_, D, F }; //constant enumeration named letter.. representation of the letter values
	//next, we need a template function
	template<typename T>
	const char* Letter_To_Grade(const T& original ) { //reference to one of the enumeration constants
		std::string letter; // a string to store the grades
		switch (original)
		{
		case Letter::A_:
			letter = "A+";
			break;
		case Letter::A:
			letter = "A";
			break;
		case Letter::B_:
			letter = "B+";
			break;
		case Letter::B:
			letter = "B";
			break;
		case Letter::C_:
			letter = "C+";
			break;
		case Letter::C:
			letter = "C";
			break;
		case Letter::D_:
			letter = "D+";
			break;
		case Letter::D:
			letter = "D";
			break;
		case Letter::F:
			letter = "F";
			break;
		default: 
			letter = "None";
		}
		return letter.c_str(); //convert into a c string

	}

}


#endif // !SICT_LETTER_H

