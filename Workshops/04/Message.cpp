
// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 03/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include<iostream>
#include<fstream>
#include<string>
#include "Message.h"

using namespace std;

namespace w4 {


	Message::Message() {}
	Message::Message(std::ifstream& in, char c)
	{
	      
		if (in.is_open()) {
			std::string input;
			std::getline(in, input, c);
			int char_tracker = 0;

			unsigned long rIndex = input.find('\n'); //find the end of line
			if (rIndex != std::string::npos) { // a way of saying that the index is not null
				input.erase(rIndex); //npos- until the end of the string
			}
			for (size_t i = 0; i < input.size() && input[i] != ' '; ++i) {
				user += input[i];
				char_tracker++;
			}
			input.erase(0, char_tracker + 1);
			int space_tracker = input.find(' '); // search for the next space

			if (input[0] == '@') { //if the first character of the line is a '@'

				for (int i = 1; i < space_tracker; ++i) {
					reply += input[i]; //copy the newly created line with data in the original string
				}
				
				space_tracker = input.find(' '); //find the next space
				input.erase(0, space_tracker); //delete all characters from the first index up until the space

			}

		      unsigned int input_size = input.size();
				if (input_size != 0) {

				}
		       
			for (size_t i = 0; i < input_size; ++i) {
				tweet += input[i];
			}
		       
		   }
		       
		       // reply.erase(0,1);
		       // tweet.erase(0,1);                
	      //  in.close();
	} 
       
       
	 bool Message::empty() const {
		bool flag = true;
		if (!tweet.empty()){
			flag= false;
		}
		return flag;
	}
	

	void Message::display(std::ostream& os) const {

		os << "Message" << endl;
		os << " User  : " << user << endl;
		if (!reply.empty()) {
			os << " Reply : " << reply << endl;
		}

		if(!tweet.empty()){        
			os << " Tweet : " << tweet << endl;
			os << endl;
		}
	}

}
