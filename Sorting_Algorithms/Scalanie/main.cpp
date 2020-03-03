
#include <iostream>
#include <stdlib.h>
#include "Scalanie.h"
#include <time.h>
#include <memory>
#include "inputs.h"
 
   int main(){
   int rozmiar=10000000;
   int *tab1= new int[rozmiar];
      
   input_min_max(tab1,rozmiar,0.5);

  
   tab1=Merge_Sort(tab1,0,rozmiar-1);
   //tab3=merge(tab3,0,(rozmiar*2-1)/2,rozmiar*2-1)
  if_sorted(tab1,rozmiar);
   return 0;
 }