// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 31/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// iProduct.h
#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6
{
	class iProduct
	{
	public:
		virtual double getPrice() const = 0;
		virtual void display(std::ostream&) const = 0;
	};
}
#endif
