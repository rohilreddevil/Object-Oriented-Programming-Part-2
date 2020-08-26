
// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include<iostream>
#include<fstream>
#include<string>
#include "Notifications.h"

using namespace std;

namespace w4 {

	Notifications::Notifications() //default constructor
	{
		message = nullptr;
		records = 0;
	}

	Notifications::Notifications(const Notifications & not) {//copy constructor
		*this = not; // this is eventually calling the copy assignment operator below
		
	/*this->records = not.records;
		if (this->message == nullptr) {
			this->message = new std::string[not.records];
		}


		for (size_t i = 0; i < not.records; i++) {
			if (this->message != nullptr) {
				this->message[i] = not.message[i];
			}
			else { this->message = nullptr; }
		}*/


	}
	Notifications::Notifications(Notifications && not) { //move constructor
		
		*this = std::move(not);
	}

	Notifications& Notifications::operator=(const Notifications& not) { //copy assignment

		if (true) {

			if (message != nullptr) {
				delete[] message; //checks for self assignment
			}
			this->records = not.records;
			message = new Message[not.records];
			for (size_t i = 0; i < not.records; i++) {
				this->message[i] = not.message[i];
			}
		}

		return *this;
	}
	Notifications& Notifications ::operator=(Notifications && not) { //move assignment 
		if (this != &not) {
			if (message != nullptr) {
				delete[] message;
			}

			this->message = std::move(not.message);
			this->records = std::move(not.records);

			not.message = nullptr;
			not.records = 0;
		}
		return *this;
	}
	Notifications::~Notifications() //destructor
	{
		delete[] message;
		message = nullptr;
	}
	void Notifications::operator+=(const Message & msg) { //operator

		if (records ==0) {
			message = new Message[msg_obj];
		}
		if (records < msg_obj) {
			message[records] = msg;
			records++;
		}

	}
	
	void Notifications::display(std::ostream& os) const { //display()
		for  (size_t i = 0; i < records; i++)
		{
			message[i].display(os); // call the display function of the MESSAGE MODULE
		}
		
	}


}