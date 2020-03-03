

 #ifndef LISTDOUBLE_H_
 #define LISTDOUBLE_H_
 #include <cstddef>
 #include <iostream>
 
template<typename T>
 class Pozycja{
    public:
    T value;
    Pozycja<T> *next;
    Pozycja<T> *previous;

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
     void push_back( const T element);
     void push_for( const T element);
     void pop_back();
     void pop_for();
     void pop();
     bool List_empty();   
     T show();
     T show_back();
     void show_all();
     int quantity();
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
void List<T>::show_all(){
  Pozycja<T> * tmp= first;
  while(!(tmp==top)){
  std::cout<<tmp->value <<std::endl;
  tmp=tmp->next;
  }}    
 template<typename T>
void List<T>::push_back(const T element){
    if(List_empty()){
      
      first=new Pozycja<T>;  // jeśli pierwszy raz cos dodajemy
      top=first;
      top->value=element;
      top->next=NULL;    
      top->previous=NULL;
      }
    else
    {
    top->next= new Pozycja<T> ;
    Pozycja<T> *tmp = top;
    top = top->next;
    top->previous=tmp;
    top->value=element;
    top->next=NULL;    
      }
      num_elements++;
      }

 template<typename T>
void List<T>::pop_back(){
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
void List<T>::push_for(const T element){
    if(List_empty()){
      
      first=new Pozycja<T>;  // jeśli pierwszy raz cos dodajemy
      top=first;
      top->value=element;
      top->next=NULL;    
      top->previous=NULL;
      }
    else
    {
    Pozycja<T> * tem= new Pozycja<T> ;
    first->previous=tem;
    tem->value=element;
    tem->next=first;
    tem->previous=NULL;
    first=tem;    
      }
      num_elements++;
      }

 template<typename T>
void List<T>::pop_for(){
if(!(first==top)){

if (!List_empty()) {
        Pozycja<T> * tmp= first;
        first=first->next;
        first->previous=NULL;
        free(tmp);
        num_elements --;  

    }
    else
    {
        std::cout<<"Empty"<<std::endl;
    }
    }
    else
    {
        free(first);
        num_elements--;
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
T List<T>::show_back(){
     if (List_empty()) {
     std::cout<< "PUSTY"<<std::endl;
         return 0;
    
     }
     
return first->value;
}

 template<typename T>
int List<T>::quantity(){
return num_elements;
}

 #endif