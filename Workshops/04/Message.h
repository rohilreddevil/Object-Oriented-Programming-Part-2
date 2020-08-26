// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef w4_MESSAGE_H
#define w4_MESSAGE_H

#include<iostream>
#include<fstream>
#include<string>

namespace w4{
	class Message
	{
		std::string user;
		std::string tweet;
		std::string reply;
	public:
		Message(); //default constructor
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}

#endif w4_MESSAGE_H