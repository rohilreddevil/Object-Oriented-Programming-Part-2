// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 31/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

#include"Product.h"

using namespace std;

namespace w6 {

	Product::Product(int NUM, double cst) {

		prod_num = NUM;
		cost = cst;

	}

	double Product::getPrice() const {
		return cost;
	}

	void Product::display(std::ostream& os) const {

		os << setw(16) << this->prod_num  << this->cost << endl;
		//this->member is the same as
		//*this.member
	}
}