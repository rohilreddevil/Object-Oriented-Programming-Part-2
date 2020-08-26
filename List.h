// Name: Rohil Khakhar		
// Seneca Student ID: 109270173
// Seneca email: rkkhakhar@myseneca.ca
// Start Date: 23/09/18
// Date of completion:
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LIST_H
#define LIST_H


	template <typename T, int N>
	class List
	{
		T arr[N];
		int records;
		//T garbage;
	public:
		List() : records(0), arr() { 
			//records = 0;
			//arr[0] = 0;
		};
		size_t size() const { return records; }
		const T& operator[](int index) const {
			//return index < N ? arr[index] : garbage;
			return arr[index];
		}
		void operator+=(const T& obj) {
			if (records < N ){
				arr[records] = obj;
				records++;
			}
		}
	};

	/*template<class T, int N>
	List<T, N>::List() {
		records = 0;
	}*/

	
#endif // !LIST_H