#ifndef _TIC_H_
#define _TIC_H_

#include <iostream>
#include <string>

class Tic {
	private:
		const int s = 3;
		char arr[3][3];
		bool X;
	public:
		Tic();
		~Tic() = default;
		void print();
		void game();
		char row_col();
		char diagonals();
		bool full(); 
		bool end();
};




#endif //_TIC_H_ 
