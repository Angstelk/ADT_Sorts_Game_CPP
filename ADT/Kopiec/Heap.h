

 #ifndef HEAP_H_
 #define HEAP_H_
 #include <cstddef>
 #include <iostream>
 #include <math.h> 
 #include <algorithm>
 template<typename T>
class Heap
{
private:
  
  int elements=15   ; // ile elementów 
  T *  nodes;   
public:
    Heap(/* args */);
    ~Heap();
void display();
int kopcowanie(int indeks);
void budowanie_kopca();
int parent(int i) {return floor(i/2);}
int left(int i) {return 2*i;}
int right(int i) {return 2*i+1;}
void usuwanie_korzenia();
void nspacja(int n);
};
template<typename T>
Heap<T>::Heap(/* args */)
{ nodes=  new T [elements];
  for(size_t i = 1; i < elements; i++)
   {nodes[i]= rand()%30;}
}
template<typename T>
Heap<T>::~Heap()
{
}

template<typename T>
void Heap<T>::nspacja(int n){
  for(size_t i = 0; i < n; i++)
  {
    std::cout<<" " ;
  }
}

template<typename T>
void Heap<T>::display(){
int rzedy = ceil(log2f(elements)) ;// do obliczenia rzedoów mamy logarytm z 2
int szerokosc = pow(2,rzedy) + pow(2,rzedy-1)*3  +4 ;// ilosc elementow + ilosc spacji na jedną oske + jaaś losc zeby od sie odciac od marginesu
//deklaracje zmiennych
int wiersze=1; // w którym wierszu jestem
int miejsce_wartosci; // ile spacji miedzy wartosciami
int osie; // ile osi w rzedzie
int pop_os;// 
// wyswietl pierwszy rzad
int r;
for(r= 1; r < elements; r++)
{ 
  std::cout<< r << " element : "<< nodes[r]<<std::endl;
}
std::cout<<std::endl<<std::endl;



}

template<typename T>
int Heap<T>::kopcowanie(int indeks)
{ int lewy=left(indeks);
  int prawy =right(indeks);
  int largest ;
  
  if(lewy <= elements && nodes[indeks]< nodes[lewy])
  {
    largest=lewy;
  }
  else
  {
    largest=indeks;
  }
  if(prawy <= elements && nodes[largest]< nodes[prawy])
  {
    largest=prawy;
  }

  if(largest != indeks && largest < elements )
   { //std::cout<< "z funkcji kopcowanie indeks :" << indeks<< "largest : "<< largest<<std::endl;
    std::swap( nodes[indeks], nodes[largest] );
    kopcowanie(largest);
   }
        return 0;
}
template<typename T>
void Heap<T>::budowanie_kopca(){
int rozmiar=elements-1;
    for(int i = floor(rozmiar/2) ; i >0 ; i--) // mam pewnosc ze biore pierwsze
    {
       //std::cout<<"Kopcuje dla i : " << i<<std::endl;// wezly nie liscie
      kopcowanie(i);
    }
}
template<typename T>
 void Heap<T>::usuwanie_korzenia(){
    T *tab;
    tab=new T(elements-1);
     for(int i = 0; i < elements-1; i++)
     {if (i==0) {tab[i]=0;
     }
     else
     {
      tab[i]=nodes[i+1] ; 
     }
     
      
     
     }
   free(nodes);
   nodes=tab;
   elements=elements-1;
   budowanie_kopca();

 }
 #endif