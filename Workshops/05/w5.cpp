// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@gmail.com
// Date of completion: 12/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include<fstream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here
	try
	{
		Grades grades(argv[1]);
		//lambda expression here
		auto letter = [](double gr) {
			if (gr <=100 && gr >=90)
			{
				return Letter::A_;
			}
			else if (gr < 90 && gr >=80)
			{
				return Letter::A;
			}
			else if (gr < 80 && gr >= 75)
			{
				return Letter::B_;
			}
			else if (gr < 75 && gr >= 70)
			{
				return Letter::B;
			}
			else if (gr < 70 && gr >= 65)
			{
				return Letter::C_;
			}
			else if (gr < 65 && gr >= 60)
			{
				return Letter::C;
			}
			else if (gr < 60 && gr >= 55)
			{
				return Letter::D_;
			}
			else if (gr < 55 && gr >= 50)
			{
				return Letter::D;
			}
			else if (gr < 50 && gr >= 0)
			{
				return Letter::F;
			}
			//return Letter::None; 
		}; 
		grades.displayGrades(ofs, letter);
	}
	catch (int) //status code(possibly)
	{
		std::cerr << argv[0] << ": File can't be opened "
			<< argv[1] << "\n";
	}

	catch (...) { //error handler for all other types
		std::cerr << "Error";
	}
	
	//Grades grades(argv[1]); //initialize the Grade constructor,accept an argument
	//grades.displayGrades(std::cout, letter);

	return 2;
	ofs.close(); //close the file
}