

 #ifndef LISTONE_H_
 #define LISTONE_H_
 #include <cstddef>
 #include <iostream>
 template<typename T>
 class Pozycja{
    public:
    T value;
    Pozycja<T> *next;

 };
 
 template<typename T>
 class List 
 {
 private:
    Pozycja<T> pozycja; 
    Pozycja<T> * top;
    Pozycja<T> * first;
    int num_elements; 
 public:
     void push( const T element);
     void pop();
     bool List_empty();   
     T show();
     int quantity();
     void show_all();
     List(/* args */);
     ~List();
 };
 
 template<typename T>
 List<T>::List(/* args */)
 {
      num_elements=0;
     pozycja.value=0;
     pozycja.next=NULL;
     top=NULL;   
     first=NULL;
 }
 template<typename T>
 List<T>::~List()
 {
 }
 template<typename T>
 void List<T>::show_all(){
  Pozycja<T> * tmp= first;
  while(!(tmp==top)){
  std::cout<<tmp->value <<std::endl;
  tmp=tmp->next;
  }

 }
 template<typename T>
 bool List<T>::List_empty(){
    if (num_elements==0) {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

template<typename T>
void List<T>::push(const T element){
    if(List_empty()){
      
      first=new Pozycja<T>;  // jeśli pierwszy raz cos dodajemy
      top=first;
      top->value=element;
      top->next=NULL;    
      }
    else
    {
    top->next= new Pozycja<T> ;
    top = top->next;
    top->value=element;
    top->next=NULL;    
      }
      num_elements++;
      }

template<typename T>
void List<T>::pop(){
Pozycja<T>* tem=first; 
if (!List_empty()) {
if(!(tem==top)){
  while(!(tem->next==top)){
      tem=tem->next;// jak wskaźnik na next to
       // top to znaczy że w dobrym miejscu jestem
 }}
    free(top);
    top=tem;
    num_elements--;
    }

    else
    {
        std::cout<<"Empty"<<std::endl;
    }
    
}
template<typename T>
 T List<T>::show(){
     if (List_empty()) {
     std::cout<< "PUSTY"<<std::endl;
         return 0;
    
     }
     
return top->value;
}
template<typename T>
int List<T>::quantity(){
return num_elements;
}

 #endif