 #ifndef INTRO_H_
 #define INTRO_H_
 #include <cstddef>
 #include <iostream>
 #include <algorithm>
 #include "Heap.h"
 #include "Quicksort.h"
 #include <time.h>
 
/***** INSERT ***********/
template <class Typ>
void Insert (Typ *tab, long N)
{
  int i, j;
  Typ temp;
      for (i=1; i<N; ++i)
      {
        temp=tab[i];
            for (j=i; j>0 && temp<tab[j-1]; --j)
              tab[j]=tab[j-1];
            tab[j]=temp;
      }
}
/************************ KONIEC INSERTA**********************/
/*********************** KOPIEC ********************************/

 
template <class Typ>
void kopcowanie (Typ *tab, long i, long N)
{
  long j;
  while (i<=N/2)
  {
    j=2*i;
    if (j+1<=N && tab[j+1]>tab[j])
      j=j+1;
    if (tab[i]<tab[j])
     std::swap(tab[i],tab[j]);
    else break;
    i=j;
  }
}
template <class Typ>
void Heap_Sort (Typ *tab, long N)
{
  long i;
  for (i=N/2; i>0; --i)
    kopcowanie(tab-1,i,N);
  for (i=N-1; i>0; --i)
  {
      std::swap(tab[i],tab[0]);
    kopcowanie(tab-1,1,i);
  }
}
/*********************** KONIEC KOPCA ***********************/
/*********************QUICK MODYFIKOWANY ***************************/
template<typename Type>
void Mediana(Type * tab ,long l, long r){
  if (tab[++l-1]>tab[--r]) std::swap(tab[l-1],tab[r]);
  if (tab[l-1]>tab[r/2])  std::swap(tab[l-1],tab[r/2]);
  if (tab[r/2]>tab[r])  std::swap(tab[r/2],tab[r]);
  std::swap(tab[r/2],tab[r-1]);
}



template<typename Type>
int Punkt_podzialu1(Type l, Type r){
return l + (r-l)/2; // zwraca indeks środka danej poddtablicy
}
template<typename Type>
int Separate1(Type * tab, int l, int r){
     
    
    int indeks=Punkt_podzialu1(l,r);
    
    Type Val_sep= tab[indeks];
    
    std::swap(tab[r],tab[indeks]); //przeniesienie elementu (wyznacznika) na koniec żeby nie był sortowany 
    int pozycja= l;
    
     for(size_t i = l; i <= r-1; i++)
    {
        if(tab[i]<Val_sep){
         std::swap(tab[pozycja],tab[i]); 
         pozycja++;
        }
    }
    std::swap(tab[r],tab[pozycja]);
    return pozycja;

}

template<typename Type>
 void Quicksort1(Type* tab, int l, int r ){
    
     if(l<r){
        int i=Separate1(tab,l,r);
        Quicksort1(tab,l,i-1);
        Quicksort1(tab,i+1,r);

     }
}
void quicksort(int tab[], int left, int right){
     int i=left;
     int j=right;
     int x=tab[(left+right)>>1];
     do{
         while(tab[i]<x) i++;
         while(tab[j]>x) j--;
         if(i<=j){                  
             int temp=tab[i];
             tab[i]=tab[j];
             tab[j]=temp;
             i++;
             j--;
         }
     }while(i<=j);
     if(left<j) quicksort(tab,left,j);
     if(right>i) quicksort(tab,i,right);     
}

/***************** KONIEC QUICKA************************************/


template <class Typ>
void IntroSort_Q (Typ *tab, long l, long r, int M)
{
  if (M<=0)
  { 
  // std::cout << " JEDZIE MELON PEWNE RZECZY NIGDY SIE NIE ZMIENIA LODZ WWA WROCLAW ZAWSZE SZCZERE ELO" <<std::endl;

    Heap_Sort(tab,r+1);
    return;
    }
    int i=l;
     int j=r;
     int x=tab[(l+r)/2];
     
     do{
         while(tab[i]<x) i++;
         while(tab[j]>x) j--;
         if(i<=j){                  
             int temp=tab[i];
             tab[i]=tab[j];
             tab[j]=temp;
             i++;
             j--;
         }
     }while(i<=j);
     
     if(l<j) IntroSort_Q(tab,l,j,M--);
     if(r>i) IntroSort_Q(tab,i,r,M--);
}


 #endif