

#ifndef Queue_H_
#define Queue_H_
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
    int num_elements;   // pamiec ktora zajmuje tablica
    int indeks_koniec;  // indeks na pierwszego elementu
    int  poczatek;      // pierwszy element
    int indeks_start;   // indeks z lewej 
    T * tab;
    int Q;
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
    Queue(/* args */);
    ~Queue();
};
template<class T>
Queue<T>::Queue(/* args */) {
    num_elements=10;
    indeks_koniec=0;
    indeks_start=0;
    poczatek=0;
    tab=new T[num_elements];   
    Q=0;
}

template<class T>
Queue<T>::~Queue() {}

template<class T>
void Queue<T>::show_all()
{
    std::cout<<"SHOW ALL"<<std::endl;
    for(size_t i = indeks_start+1; i < indeks_koniec; i++) {
        std::cout<< i <<" element :"<< tab[i]<<std::endl;
    }
    
}

template<class T>
void Queue<T>::extend_Queue(){
    num_elements=num_elements*2;
    T* tmp= new T[num_elements]; //nowa tablica i pamiec jest dodawana z prawej strony 

    for(size_t i = 0; i < num_elements; i++)
       tmp[i]=tab[i];
    
    delete[](tab);
    tab = tmp;
}


template<class T>
void Queue<T>::push(const T element){
    if (!(indeks_start==0)) { 
        indeks_start--;
        Q++;                       // jak z lewej jest jeszcze miejsce 
        tab[indeks_start]=element; // dodaj od lewej strony  
    }
    else{
                          // 
        Q++;
        if(indeks_koniec >= num_elements)
        extend_Queue();
        tab[indeks_koniec]=element;    
         indeks_koniec++;
    }
    
    
}
template<class T>
void Queue<T>::shorter_Queue(){
        T* tmp= new T[Q];
        for(size_t i = 0; i  < Q; i++) tmp[i]=tab[i+indeks_start];
        delete[] tab;
        tab = tmp;

}
template<class T>
void Queue<T>::pop() {
    if (!Queue_empty()) 
    {  
        indeks_start ++;// indeks poczatku tablicy w prawo
        Q--;           // ilosc elementow sie zmniejsza     
        if (num_elements -Q > 10) {
        shorter_Queue();
        }
        
        
    } else {
        std::cout<<"kolejka pusta"<<std::endl;
    }
}

template<class T>
T Queue<T>::show() {
    if (Queue_empty()) {
        std::cout<< "PUSTA"<<std::endl;
        return 0;
    } 
    return tab[0];
}

template<class T>
int Queue<T>::quantity(){
    return Q;//num_elements-1;
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