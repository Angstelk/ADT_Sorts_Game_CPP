#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include "Stack1.h"

int main() {

	Stack <int>stc;

	int i=0;
	std::cout<< "Dodanie do stosu m elementów"<<std::endl;

	while(i<12) {
		stc.push((rand() % 100));
		//std::cout << stc.show()<<std::endl;
		i++;
	}
     //stc.show_all();
	i=0;
	stc.show_all();
	std::cout<< "Usuniecie ze stosu k elementów"<<std::endl;
	while(i<10) {
		//std::cout << stc.show()<<std::endl;
		stc.pop();
		i++;
	}
	i=0;
	//stc.show_all();
	stc.pop();
	std::cout<< "Dodanie do stosu elementu"<<std::endl;
	stc.push(3);
	std::cout << stc.show()<<std::endl;
	std::cout<< "Ilosc elementów"<<std::endl;
	std::cout << stc.quantity()<<std::endl;

	return 0;

}