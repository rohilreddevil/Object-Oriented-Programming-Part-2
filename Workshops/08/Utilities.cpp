// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Start Date: 15/11/2018
// Date of completion: 15/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		Product*prod;
		for (size_t a = 0; a < desc.size(); a++)
		{
			for (size_t b = 0; b < price.size(); b++) //list building for the 2 elements in the parameter
			{
				if (desc[a].code == price[b].code) //if the product codes do match
				{
					prod = new Product(desc[a].desc, price[b].price); //calling the constructor in element.h
					prod->validate();
					priceList += prod; //passing the raw pointer to the += operator
					delete prod; //only applies to the raw pointer version. This isn't as smart as smart pointers
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		
		for (size_t a = 0; a < desc.size(); a++)
		{
			for (size_t b = 0; b < price.size(); b++) //list building for the 2 elements in the parameter
			{
				if (desc[a].code == price[b].code) //if the product codes do match
				{
					std::unique_ptr<Product> prod  (new Product(desc[a].desc, price[b].price));
					prod->validate();
					priceList += std::move (prod); //ownership transfer using move
					
				}
			}
		}


		return priceList;
	}
}