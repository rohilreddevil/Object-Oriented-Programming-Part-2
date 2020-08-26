// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Start Date: 23/09/18
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef PAIR_H
#define PAIR_H


template<class A, class B>
class Pair
{
	A a; 
	B b;
public:
	Pair() {
		a = '\0';
		b = 0.0; //calls the default constructor for a safe empty state
	}
	Pair(const A& first, const B&second) {
		a = first;
		b = second;
	}
	const A& getKey() const { return a; }
	const B& getValue() const { return b; }

};

#endif // !1