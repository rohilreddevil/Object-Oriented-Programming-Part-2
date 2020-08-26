// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 18/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include<iostream>
#include<fstream>
#include <string>
#include "Text.h"

using namespace std;

namespace w2 {

	Text::Text() {
		records = 0;
		actual = nullptr;
	}

	Text::Text(const char* ch) //one argument constructor
	{
		// gutenberg_shakespeare.txt

		ifstream file(ch);

		string line;
		records = 0;
		actual = nullptr;

		if (!file.is_open()) {
			return;
		}


		//	size_t count = 0;


		while (getline(file, line)) {

			records++;
		}
		file.clear();
		file.seekg(0);

		//cout << "count: " << records<< endl;
		actual = new std::string[records];
		for (size_t i = 0; getline(file, line); ++i)
		{
			actual[i] = line;
		}

		file.close();
	}


	Text::Text(const Text& txt) { //copy constructor
		this->records = txt.records;
		for (size_t i = 0; i < records; i++) {
			this->actual[i] = txt.actual[i];
		}
	}

	Text::Text(Text&& txt) { //move constructor
		actual = std::move(txt.actual);
		records = std::move(txt.records);

		txt.actual = nullptr;
		txt.records = 0;
	}
	Text& Text::operator=(const Text& txt) { //copy assignment operator

		if (this != &txt) {
			if (actual != nullptr) {
				delete[] actual;
			}
			this->records = txt.records;
			actual = new string[records];
			for (size_t i = 0; i < records; i++) {
				this->actual[i] = txt.actual[i];
			}
		}

		return *this;
	}
	Text& Text::operator=(Text&& txt) { //move assignment operator

		if (this != &txt) {
			if (actual != nullptr) {
				delete[] actual;
			}
			
			this->actual = std::move(txt.actual);
			this->records = std::move(txt.records);

			txt.actual = nullptr;
			txt.records = 0;
		}
		return *this;
	}
	Text::~Text() //destructor
	{
		cout << "AA";
		if (actual != nullptr) {
			delete[] actual;
			actual = nullptr;
		}
	}
	size_t Text::size() const { //returns the number of records
		return records;
	}

}