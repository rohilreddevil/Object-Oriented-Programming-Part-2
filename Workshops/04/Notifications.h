
// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef w4_NOTIFICATIONS_H
#define w4_NOTIFICATIONS_H

#include<iostream>
#include<fstream>
#include"Message.h"


namespace w4 {

	const int msg_obj = 10; //pre defined number of Message Objects that can be managed
	class Message; //forward Declaration of component class
				   //notification includes a message

	class Notifications
	{
		 Message* message = nullptr;
		int records; //counts the records of messages

	public:
		Notifications(); //pre-provided constructor
		Notifications(const Notifications&); //copy constructor
		Notifications(Notifications&&); //move constructor
		Notifications& operator=(const Notifications&); //copy assignment operator
		Notifications & operator=(Notifications&&); //move assignment operator
		~Notifications(); //destructor
		void operator+=(const Message& msg); //adds message to the set
		void display(std::ostream& os) const; //inserts message objects to the os stream
	};

}

#endif w4_NOTIFICATIONS_H