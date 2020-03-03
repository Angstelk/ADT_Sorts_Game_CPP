#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include "List_two.h"

int main()
{
List<float> stc;
int i=0;
 std::cout<< "Dodanie do listy m elementów"<<std::endl;
    while(i<=20){
   
       stc.push_back( rand()%100);
         i++;
   }
  i=0;
   std::cout<< "Pokazanie listy"<<std::endl;
   stc.show_all();
std::cout<< "Dodanie do listy k elementów na poczatku"<<std::endl;
   while(i<=10){
   
       stc.push_for(rand() % 100);
       
         i++;
   }
  i=0;
 std::cout<< "Usuniecie z listy l elementów na poczatku"<<std::endl;
        while(i<=4){
   
       stc.pop_for();
         i++;
   }
  i=0;
std::cout<< "Pierwszy element listy"<<std::endl;
std::cout<< stc.show()<<std::endl; 
 std::cout<< "Usuniecie z listy k elementów z konca"<<std::endl;
     while(i<=4){
   
       stc.pop_back();
         i++;
   }
i=0;
std::cout<< "Pokaz ostatni element z listy"<<std::endl;
std::cout<< stc.show_back()<<std::endl; 
std::cout<< "Zawartosc listy"<<std::endl;
stc.show_all();

i=0;
std::cout<< "Usuniecie elementów z listy"<<std::endl;
while(!(0==stc.quantity())){    
       stc.pop_back();
         i++;
   }
  i=0;
  std::cout<< "Liczba elementów"<<std::endl;
std::cout<< stc.quantity()<<std::endl;




   
    return 0;
}