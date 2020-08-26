// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 31/10/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}
	std::cout << std::fixed << std::setprecision(2);

	// TODO: Define a variable of type vector named "products"
	std::vector<w6::iProduct*> products;

	std::cout << "====================================\n";
	std::cout << "Reading data from the file\n";
	std::cout << "====================================\n";
	
		// TODO: Read from the file one record at a time and create a product
		//   - Print a message before starting processing a product.
		//   - Add the product to the vector "products", created above.
		//   - Handle any thrown exceptions and print the message.


	//Reading from a file

		int count = 0;
		std::string str;
		//std::ifstream myfile("sales.dat");
		while(!productList.eof()){
		
			getline(productList, str);
			count++;
		} 
	
		productList.clear();
		productList.seekg(0, std::ios::beg); //stream from the beginning of the file

		for (int i = 0; i < count; i++) {
			try {
				products.push_back(w6::readProduct(productList)); //push_back indicates pushing elements to the end of the vector
			}
			catch (std::string err) {
				std::cerr << err;
				return 2;
			}
		}

	
	std::cout << "====================================\n";

	std::cout << std::endl;
	std::cout << "====================================\n";
	std::cout << "Printing the content of the vector\n";
	std::cout << "====================================\n";

	double total = 0.0;
	std::cout << "      Product No         Taxable\n";
	std::cout << "------------------------------------\n";
	for (auto i = 0u; i < products.size(); i++) {
		total += products[i]->getPrice();
		std::cout << *products[i];
	}
	std::cout << "------------------------------------\n";
	std::cout << std::setw(22) << "Total: ";
	std::cout << std::setw(10) << total << std::endl;
	std::cout << "====================================\n";

	return 0;
}