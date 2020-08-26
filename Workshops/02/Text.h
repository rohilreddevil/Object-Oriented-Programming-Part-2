// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 18/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W2_TEXT_H
#define W2_TEXT_H



namespace w2 {

	class Text
	{
		//char* name = new char[10];
		//char*name[10];
		
		std::string* actual; //dynamic memory for this array
		size_t records;
		//short*resource;
	public:
		Text(); //default constructor
		Text(const char*); // one argument constructor
		~Text(); //destructor
		Text(const Text&); //copy constructor
		Text& operator=(const Text&); //copy assignment operator
		Text(Text&&); //move constructor
		Text& operator=(Text&&); //move assignment operator
		size_t size() const; //returns the number of records
		
	};

}

#endif // !W2_TEXT_H