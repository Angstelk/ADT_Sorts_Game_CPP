

#ifndef STACK1_H_
#define STACK1_H_
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

template<typename T>
class Stack
{
private:
    int num_elements;
    int indeks; 
    T * tab;
    int S;
public:
    void push( const T element);
    void pop();
    bool stack_empty();   
    T show();
    int quantity();
    void extend_stack();
    void show_all();
        
    Stack(/* args */);
    ~Stack();
};
template<class T>
Stack<T>::Stack(/* args */) {
    num_elements=10;
    indeks=-1;
    tab=new T[num_elements];   
    S=0;
}

template<class T>
Stack<T>::~Stack() {}

template<class T>
void Stack<T>::show_all()
{
    std::cout<<"SHOW ALL"<<std::endl;
    for(size_t i = 0; i < indeks; i++) {
        std::cout<< i <<" element :"<< tab[i]<<std::endl;
    }
}

template<class T>
void Stack<T>::extend_stack(){
    num_elements=num_elements*2;
    T* tmp= new T[num_elements]; //nowa tablica

    for(size_t i = 0; i < num_elements; i++)
       tmp[i]=tab[i];
    
    delete[](tab);
    tab = tmp;
}


template<class T>
void Stack<T>::push(const T element){
    indeks++;
    S++;
    if(indeks >= num_elements)
        extend_stack();

    tab[indeks]=element;
}

template<class T>
void Stack<T>::pop() {
    if (!stack_empty()) 
    {  
        indeks --;
        num_elements--;
        S--;
        T* tmp= new T[num_elements];

        for(size_t i = 0; i  <= indeks; i++)
            tmp[i]=tab[i];
        
        delete[] tab;
        tab = tmp;
    } else {
        std::cout<<"Stos pusty"<<std::endl;
    }
}

template<class T>
T Stack<T>::show() {
    if (stack_empty()) {
        std::cout<< "PUSTY"<<std::endl;
        return 0;
    } 
    return tab[indeks];
}

template<class T>
int Stack<T>::quantity(){
    return S;//num_elements-1;
}

template<class T>
bool Stack<T>::stack_empty() {
    if (indeks<=0) {
        return true;
    }
    else
    {
        return false;
    }
}

#endif