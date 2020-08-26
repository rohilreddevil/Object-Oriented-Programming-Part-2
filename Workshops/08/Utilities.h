// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Start Date: 15/11/2018
// Date of completion: 15/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#ifndef W8_UTILITIES_H
#define W8_UTILITIES_H
#include "List.h"
#include "Element.h"

namespace w8 {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif