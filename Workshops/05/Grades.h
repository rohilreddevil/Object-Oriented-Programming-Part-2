// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@gmail.com
// Date of completion: 12/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include<iostream>
#include<fstream>
#include<string>
#include"Letter.h"

namespace sict {

	class Grades {

		int records; //keeping track of the rows in the file
		std::string* STUDENT_NUMBER; //since its dynamic memory allocation
		double* GRADE;

	public:

		Grades(): STUDENT_NUMBER(nullptr), GRADE(0), records (0) {} //default constructor
		
		Grades(std::string FILENAME); // string containing the name of the file that has all the data
		
		Grades(const Grades & gr) = delete;
		Grades&operator=(const Grades& gr) = delete;
		Grades(Grades && gr) = delete;
		Grades&operator=(Grades&& gr) = delete;
		template<typename T> //template function follows
		void displayGrades(std::ostream& os, T F) const {

			for (int i = 0; i < records; i++)
			{
				auto letter = F(GRADE[i]);
				os.precision(2); //set the values to 2 decimal places
				
				os << STUDENT_NUMBER[i].c_str() << " " << std::fixed << GRADE[i] << " ";
				os.width(4); //spacing and alignment
				os << std::left << Letter_To_Grade(letter) << std::endl;
				//os << F(GRADE[i]) << std::endl; //calling the constructor ?
			}
		}
	};

}


#endif // !SICT_GRADES_H

