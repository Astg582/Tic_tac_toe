#ifndef _TIC_HPP_
#define _TIC_HPP_
#include <iostream>
#include <string>
#include "Tic.h"


Tic::Tic(){ 
	for(int i = 0; i < s; ++i){
		for(int j = 0; j < s; ++j){
			this->arr[i][j] = '_';
		}
	}
	this->X = true;
}

void Tic::print(){
	for(int i = 0; i < this->s; ++i){
		std::cout << std::endl;
		for(int j = 0; j < this->s; ++j){
			std::cout << this->arr[i][j];
		}
	}
	std::cout << std::endl;
}

void Tic::game(){
	int cx = 0;
	int cy = 0;
	std::cout << "Enter coordinates from 1 to 3 :" ;
	std::cin >> cx;
	std::cin >> cy;
	if((cx < 4) && (cx > 0) && (cy < 4) && (cy > 0) && (this->arr[cx - 1][cy - 1] == '_')){
		if(this->X){
			this->arr[cx - 1][cy - 1] = 'X';  
			X = !X;
		}else {
			this->arr[cx - 1][cy - 1] = 'O';
			X = !X;
		}
	} else {
		return;
	}
}

char Tic::row_col(){
	short x = 0;
	short o = 0;
	short cx = 0;
	short co = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(this->arr[i][j] == 'X'){
				++x;
			}
			if(this->arr[j][i] == 'X'){
				++cx;
			}
			if(this->arr[i][j] == 'O'){
				++o;
			}
			if(this->arr[j][i] == 'O'){
				++co;
			}
		}
		if(x == 3 || cx == 3){
			return 'X';
		}

		if(o == 3 || co == 3){
			return 'O';
		}

		x = 0;
		o = 0;

		cx = 0;
		co = 0;
	}		
	return ' ';
}



char Tic::diagonals(){
	short x = 0;
	short o = 0;

	short ax = 0;
	short ao = 0; 
	for(int  i = 0; i < 3; ++i){
		if(this->arr[i][i] == 'X'){
			++x;
		} else if (this->arr[i][i] == 'O'){
			++o;
		}
		
		if(this->arr[i][2 - i] == 'X'){
			++ax;
		} else if(this->arr[i][2 - i] == 'O'){
			++ao;
		}	
		
		if(x == 3 || ax == 3){
			return 'X';
		}
		if(o == 3 || ao == 3){
			return 'O';
		}

	}

	return ' ';
}

bool Tic::full(){
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(this->arr[i][j] == '_'){
				return false;
			}	
		}
	}
	return true;
}

bool Tic::end(){
	char d = this->diagonals();
	char rc = this->row_col();
	if(d == 'X' || rc == 'X'){
		std::cout << "WIN X " << std::endl;
		return true;
	}else if (d == 'O' || rc == 'O'){
		std::cout << "WIN O" << std::endl;
		return true;
	}
	if(full()){
		std::cout << "GAME OWER" << std::endl;
		return true;
	}
	return false;
}

#endif // _TIC_HPP_
