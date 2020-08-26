
// Name: Rohil Khakhar
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Date of completion: 8/11/18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef  W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<cmath>

namespace w7 {

	template<typename T>
	class DataTable {

		int field_width;
		int no_decimals;

		std::vector<T> x_axis;
		std::vector<T> y_axis;

	public:

		DataTable(std::ifstream& ifs, int fw, int no_dec) {
			
			field_width = fw;
			no_decimals = no_dec;

			T x, y; //variables of type T

			while (!ifs.eof()) //while the file has not reached its end point
			{
			
				ifs >> x >> y;

				x_axis.push_back(x); //pushing the values to the end of the x axis vector
				y_axis.push_back(y); //pushing the values to the end of the y axis vector

			}


		}

		T mean() const{
		
			T sum = std::accumulate(y_axis.begin(), y_axis.end(), (T)0); //y values are the dependent value
			T num = y_axis.size(); //number of elements

			return sum / num;

		}
		T sigma() const {

			T mean = mean();
			T num = y_axis.size();

			T numerator = std::accumulate(y_axis.begin(), y_axis.end(), (T)0, [=](T x, T y) {
				return x + (y - mean())*(y - mean()); }) / (num - 1);
				return (T)std::sqrt(numerator);

		}
		T median() const {
			
			T num = y_axis.size();
			std::vector<T> arrange = this->y_axis; //dependent value
			std::sort(arrange.begin(), arrange.end());// arrange the y axis elements to find the middle number in the list of sorted y values
			return arrange[num / 2];

		}
		void regression(T& slope, T& y_intercept) const {

			T num = y_axis.size();

			T sumX = std::accumulate(x_axis.begin(), x_axis.end(), (T)0);

			T sumY = std::accumulate(y_axis.begin(), y_axis.end(), (T)0);

			T sum_xy = std::inner_product(x_axis.begin(), x_axis.end(), y_axis.begin(), (T)0);

			T sum2 = std::inner_product(x_axis.begin(), x_axis.end(), x_axis.begin(), (T)0);
		
			slope = (num*sum_xy - (sumX*sumY)) / (num*sum2 - sumX*sumX);

			y_intercept =  (sumY -slope*sumX) / num;
		}
		void display(std::ostream&os) const {

			os <<std::setprecision(no_decimals);
			os << std::setw(field_width) << "x" << std::setw(field_width) << "y" << std::endl;

			for (int i = 0; i < x_axis.size(); i++)
			{
				os << std::setw(field_width) << x_axis[i] << std::setw(field_width) << y_axis[i] << std::endl;
			}

		}
		size_t getSize() const {
			
			return y_axis.size();
		
		}
		friend std::ostream& operator<<(std::ostream&os, const DataTable&dt) {

			dt.display(os); //calls the display function as specified.
			return os;

		}
	};

}

#endif // ! W7_DATATABLE_H