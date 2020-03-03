

#ifndef Queue_list_H_
#define Queue_list_H_
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

template<typename T>
class Queue
{
private:
    int num_slots;   // pamiec ktora zajmuje tablica
    int indeks_l;  // indeks na pierwszego elementu l lewej
    int  pierwszy_element;      // pierwszy element
    int indeks_r;   // indeks ostatniego elementu z prawej 
    T * tab;         // tablcia 
    int Q;   // ilosc wartosci w kolejce
//zawijanie przy puszu 
public:
    void push( const T element);
    void pop();
    bool Queue_empty();   
    T show();
    int quantity();
    void extend_Queue();
    void show_all();
    void shorter_Queue();
    void show_tab();
    Queue(/* args */);
    ~Queue();
};
template<class T>
Queue<T>::Queue(/* args */) {
    num_slots=10;
    indeks_r=0;
    indeks_l=0;
    pierwszy_element=0;
    tab=new T[num_slots];   
    Q=0;
}

template<class T>
Queue<T>::~Queue() {}
template<class T>
void Queue<T>::show_tab(){
    for(size_t i = 0; i < Q; i++) {
        // std::cout<<"WYKONALEM SIE" <<std::endl;   
        std::cout<<" tablica :"<< tab[i]<<std::endl;
    }
}

template<class T>
void Queue<T>::show_all()
{ int k=0;
    std::cout<<"SHOW ALL"<<std::endl;
    for(size_t i = pierwszy_element; i < indeks_r; i++,k++) {
       
        std::cout<< k <<" element :"<< tab[i]<<std::endl;
    }

    for(size_t i = pierwszy_element; i > indeks_l; i--,k++) {
         
        std::cout<< k <<" element :"<< tab[i]<<std::endl;
    }
}

template<class T>
void Queue<T>::extend_Queue(){
    num_slots=num_slots*2;
    int i=0;
    T* tmp= new T[num_slots]; //nowa tablica i pamiec jest dodawana z prawej strony 

    for( i = 0; i < indeks_r; i++)
       tmp[i]=tab[i+pierwszy_element];
    for(size_t k = indeks_l; k > 0; k--,i++)
    {
        tmp[i]=tab[k];
    }
    indeks_l=0;
    pierwszy_element=0;
    indeks_r=Q;
    delete[](tab);
    tab = tmp;
}


template<class T>
void Queue<T>::push(const T element){
   if (num_slots>Q) {  // jeśli wgle jest miejsce 
    // na pczatku dodaje z prawej
    if (num_slots>indeks_r) {
         //jesli jest miejsce z prawej   
       tab[indeks_r]=element;
       indeks_r++;
       Q++;
       
    }
    else       // jesli jest miejsce i nie ma miejsca z prawej to jest miejsce z lewej
    {
        tab[indeks_l]=element;
        indeks_l--;
        Q++;
    }
   }  
   

   else  // jesli nie ma miejsca to extend queue
   {
       extend_Queue();
       // jest przesuniete to dodaje z prawej
        
       tab[indeks_r]=element;
       indeks_r++;
       Q++;
       

       
   }
   
    
    
}
template<class T>
void Queue<T>::shorter_Queue(){
    int i=0;
    num_slots= num_slots-Q;
    T* tmp= new T[num_slots]; //nowa tablica i pamiec jest dodawana z prawej strony 
    
    for( i = 0; i < indeks_r; i++)tmp[i]=tab[i+pierwszy_element];
    for(size_t k = indeks_l; k > 0; k--,i++)
    {
        tmp[i]=tab[k];
    }
    indeks_l=0;
    pierwszy_element=0;
    indeks_r=Q;
    delete[](tab);
    tab = tmp;
}
template<class T>
void Queue<T>::pop() {
    if (!Queue_empty()) 
    { 
      if (indeks_l<pierwszy_element) {
         indeks_l++; 
      }                                //jesli jest cokolwiek z lewej to od tego zaczynamy 
     else
     {
         indeks_r --;
     }
     Q--;
     if(num_slots>2*Q){
         shorter_Queue();
     }
    }
}

template<class T>
T Queue<T>::show() {
    if (Queue_empty()) {
        std::cout<< "show : KOLEJKA PUSTA"<<std::endl;
    } 
  else
  {
      std::cout<< tab[pierwszy_element]<<std::endl;   
  }
  return 0;
}

template<class T>
int Queue<T>::quantity(){
    return  Q;
}

template<class T>
bool Queue<T>::Queue_empty() {
    if (Q==0) {
        return true;
    }
    else
    {
        return false;
    }
}

#endif