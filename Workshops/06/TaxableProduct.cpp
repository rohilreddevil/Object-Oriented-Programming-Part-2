// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 31/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include<iostream>
#include<iomanip>
#include"TaxableProduct.h"

using namespace std;

namespace w6 {

	TaxableProduct::TaxableProduct(int NUM, double cst, char tx) : Product(NUM, cst){
		tax = tx;
	}

	double TaxableProduct::getPrice() const {
		double tax_p = 0.00;
		if(tax == 'H'){
		
			tax_p = Product::getPrice() + (Product::getPrice() * t_rate[1]);
		}
		else if (tax == 'P') {
			tax_p = Product::getPrice() + (Product::getPrice() * t_rate[0]);
		}
		else {
			tax_p = Product::getPrice();
		} 
		return tax_p;
	}

	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		if (this->tax == 'H') {
			os << 'HST';
		}
		else {
			os << 'PST';
		}

		os << std::endl;
	}

	double TaxableProduct::t_rate[3] = { //initialize the static array members here.

		(double)TaxableProduct::rates::HST / 100, // since the enum members are initially set to int, they have to be casted to double to accomodate the tax rate
		(double)TaxableProduct::rates::PST / 100

	};
}