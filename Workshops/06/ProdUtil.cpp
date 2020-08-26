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
#include<sstream>
#include"ProdUtil.h"
#include"Product.h"
#include"iProduct.h"
#include"TaxableProduct.h"

namespace w6 {

	std::ostream& operator << (std::ostream& os, const iProduct& ip) {

		ip.display(os);
		//os << ip << std::endl;
		return os;

	}

	iProduct*readProduct(std::ifstream& f) {


		//iProduct*prod; //dynamic
		std::string st;
		getline(f, st); //extract characters from f and store them into the new string

		if (!st.empty()) {
			std::istringstream stream(st);
			int p_num;
			//int p_num; // new variables to store the file data
			double price;
			char TAX;
			iProduct*prod; //dynamic


			stream >> p_num >> price >> TAX;

			if (TAX == 'H' || TAX == 'P') {
				prod = new w6::TaxableProduct(p_num, price, TAX);
			}

			else if (TAX == 'C' || TAX == 'M') {
				throw std::string("Unrecognizable Tax Code!");
			}
			else
			{
				prod = new w6::Product(p_num, price);
			}
			return prod;
		}
		else
		{
			throw std::string("no such record! Reached the end of the file!");
			return nullptr;
		}
	}
}
		/*int find1 = st.find(" ", 0); // 0 indicates that the entire string is searched for space (starting from the first character)
		//check for tax
		int find2 = st.find(" ", find1 + 1); 

	
		//bool check = ((st.length() - 2) == find2) && (st.back() == 'H' || st.back() == 'P');
		bool check = (st.back() == 'H' || st.back() == 'P');
		//if any tax symbol if found, it is valid.. back() indicates the last element of the string.. front() indicates the first

		p_num = std::stoi(st.substr(0, find1)); // convert string to an integer to accomodate the product number
		price= std::stod(st.substr(find1, find2));// convert string to a double to accomodate the price

		if (!check == true) { 
			std::string msg= "Unrecognizable Tax Code!";
			 throw msg;
		}
		else if (!check == false) {
			prod = new TaxableProduct(p_num, price, st.back()); // st.back() indicates there is a TAX letter at the very end of the string.. hence a new TaxableProduct object can be created
			//call the TaxableProduct constructor
		}
		else { // if the product is not taxable, create an object of a regular product type
			prod = new Product(p_num, price); // pass control to the Product Constructor
		
		}
		if (st.empty()) { prod = nullptr; }
	
		return prod; //return the appropriate object
	}*/

