#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include "List_one.h"

int main()
{
List<float> stc;
int i=0;
    while(i<=4){
   
       stc.push(0.3);
         i++;
   }
  i=0;
   std::cout << stc.show()<<std::endl;
   stc.show_all();
    

 std::cout<< stc.show()<<std::endl;
   
    return 0;
}