#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include "Queue_list.hpp"

int main()
{
Queue<int> stc;
 int i=0;
 for(size_t i = 0; i < 90; i++)
 {
   stc.push(rand()%100);
 }
 stc.show();
  for(size_t i = 0; i < 100; i++)
 {
   stc.pop();
 }
 
  stc.show_all();
 for(size_t i = 0; i < 6; i++)
 {
   stc.push(rand()%100);
 }
 
 stc.show();
 std::cout<<stc.quantity()<<std::endl;
}
