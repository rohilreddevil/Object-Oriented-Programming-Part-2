// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 31/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include<iostream>
#include "iProduct.h"

namespace w6 {

	class Product: public iProduct {
		int prod_num;
		double cost;

	public:
		double getPrice() const;
		void display(std::ostream&) const;
		Product(int, double);
	};


}

#endif // !W6_PRODUCT_H
