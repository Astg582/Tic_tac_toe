#include <iostream>
#include <string>
#include "Tic.hpp"


void tic_tac_toe(Tic& ob){
	if(ob.end()){
		return;
	}
	ob.game();
	ob.print();
	return tic_tac_toe(ob);
}


int main(){
Tic ob;

tic_tac_toe(ob);
}
