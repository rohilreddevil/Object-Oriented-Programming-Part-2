// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@gmail.com
// Date of completion: 12/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include<iostream>
#include<fstream>
#include<string>

#include"Grades.h"

namespace sict {

	Grades::Grades(std::string FILENAME) { //the function that manages information storage

		std::fstream in(FILENAME); //create a new file

		if (in.is_open()) {

			std::string str; 
			while (std::getline(in, str)) {

				records++; //I will know how many records are there in this file

			}

			STUDENT_NUMBER = new std::string[records];
			GRADE = new double[records];

			in.clear(); 
			in.seekg(0); //setting the position of the cursor to 0

			for (int i = 0; i < records; i++)
			{
				in >> STUDENT_NUMBER[i];
				in.ignore( 1, ' ');
				in >> GRADE[i];
				in.ignore(1, '\n');

			}
			in.close();

		}

	}
}