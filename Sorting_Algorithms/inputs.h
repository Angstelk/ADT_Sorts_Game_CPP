     #ifndef INPUTS_H_
 #define INPUTS_H_
 #include <cstddef>
 #include <iostream>
// odwracanie tablicy 

template< class Typ>
   Typ* reverse_sorted1(Typ *tab, int rozmiar){
        input_min_max(tab,rozmiar,1);
        for(size_t i = 0; i < rozmiar/2; i++)
        {
            std::swap(tab[i],tab[rozmiar-1]);
        }
        
    return tab;
   }

template< class Typ>
   Typ* reverse_sorted(Typ *tab, int rozmiar){
        if (rozmiar<50000 ) {
             tab[0]=rand()%1000000000;// żeby zaczynać od dużych liczb;
        }
        else{
            tab[0]=rand()%(20000000000*rozmiar);// żeby zaczynać od dużych liczb;
        }
         
         //uporządkowane co raz mniejsze
        for(int k =1; k <rozmiar; k++)
        {   
            tab[k]=tab[k-1]-rand()%10;
        }
    return tab;
   }
    template< class Typ>
       bool if_sorted(Typ *tab, int rozmiar ){
        for(size_t i = 1; i < rozmiar; i++)
        {
            if (tab[i]>=tab[i-1] ){
            }
            else
            { std::cout<< "(if_sorted): TABLICA NIEPOSORTOWANA,  i= "<< (i-1) <<std::endl;  
                return false;
            }
           
        } 
         return true;

       }


 // funkcje do generowania tablic 
    template< class Typ>
     Typ* rand_input( Typ *tab,int rozmiar ,float procent){
              
        int k = 1;
        if (rozmiar<50000 ) {
        tab[0]=rand()%10000;// żeby zaczynać od dużych liczb;
        }
        else
        {
            tab[0]=rand()%rozmiar;// żeby zaczynać od dużych liczb;
        }            
        for(; k < rozmiar*procent; k++)
        {   
            tab[k]=rand()% ( tab[k-1] );
        }
        
        // losowe
        
        for(size_t i = k; i < rozmiar; i++)
        { 
            tab[i] =rand()%(tab[k-1]);  
        }
    return tab;
    }
          
   template< class Typ>       
     int  input_min_max( Typ *tab, int rozmiar, float procent ){
       int k=0;
       //zaczynamy od małych
        if (procent==1) {
             
            reverse_sorted(tab,rozmiar);
             
            return 0;
        }
        else
        {
        for(k= 0; k < rozmiar*procent; k++)
        { if (k==0) {
          
            tab[k]= rand()%20;
        
        }
        else
        {
         tab[k]= rand()%10 +tab[k-1];   
        
        }}
        int ostatnio_sortowana=k;     
        for(; k < rozmiar; k++)
        {
          if (ostatnio_sortowana==0) {
            tab[k]=rand()%10;

        }
        else
        {
         tab[k]=rand()% 10+tab[ostatnio_sortowana];  
        
        }
        
            
        }}
     return 1;
     }       
 
   template< class Typ>       
     void print_tab( Typ *tab, int rozmiar ){
    for(size_t i = 0; i < rozmiar; i++)
    {
        std::cout<< i << " element : " << tab[i] <<std::endl;
    }


     }

 #endif
