#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include "inputs.h"
#include "Quicksort.h"
#include <algorithm>
 int main(){
   int rozmiar=10;
   int tab[rozmiar];
   reverse_sorted(tab,rozmiar);
   print_tab(tab,rozmiar);
   std::cout<<std::endl;
   Quicksort(tab,0,9);
   print_tab(tab,rozmiar);
   return 0;
 }