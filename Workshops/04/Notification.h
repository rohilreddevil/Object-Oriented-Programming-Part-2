#ifndef w4_NOTIFICATION_H
#define w4_NOTIFICATION_H

#include<iostream>
#include<fstream>
#include"Message.h"


namespace w4 {

	const int msg_obj = 10; //pre defined number of Message Objects that can be managed
	class Message; //forward Declaration of component class
	//notification includes a message

	class Notification
	{
		Message* message = nullptr;
		int records; //counts the records of messages

	public:
		Notification(); //pre-provided constructor
		Notification(const Notification&); //copy constructor
		Notification(Notification&&); //move constructor
		Notification& operator=(const Notification&); //copy assignment operator
		Notification & operator=(Notification&&); //move assignment operator
		~Notification(); //destructor
		void operator+=(const Message& msg); //adds message to the set
		void display(std::ostream& os) const; //inserts message objects to the os stream
	};

}

#endif w4_NOTIFICATION_H