// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 31/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include<iostream>
#include"Product.h"

namespace w6 {

	class TaxableProduct : public Product {
		
		//const double HST = 13.00, PST = 8.00;
		char tax;
		enum class rates {HST = 13, PST= 8};
		//std::array<double, 2> num = { 0.8, 0.13 };
		static double t_rate[3]; // static class array to store the tax rates for HST and PST
		//int p_num;
	public:
		double getPrice() const;
		void display(std::ostream&) const;
		TaxableProduct(int, double, char);
	};


}

#endif // !W6_PRODUCT_H

