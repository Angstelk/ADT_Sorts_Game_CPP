
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std;


void add_elements(stack<int> * s, int m)
{ int i=0;

    while (i < m )
    {
        s->push(rand() % 100);
        i++;
    }

}
bool remove_elements(stack<int> * s, int k)
{ int i=0;
    while (i < k)
    {
        if(!s->empty()){
        s->pop();
        i++;}
        else
        {
            cout << "Mam blad"<<endl;
            return false;
        }
        
    }
 return true;
}

int main()
{
    stack<int> s;
    int i = 0;
    int stack_elements = 7;
    int stack_rm_elemets=10;
    stack<int> * pointer;
    pointer=&s;
    add_elements(pointer,stack_elements);
    if(!s.empty())cout << "The last value from stack : " << s.top()<<endl;
    remove_elements(pointer,stack_rm_elemets);
    if(!s.empty())cout << "The last value from stack: " << s.top()<<endl;
    s.push(rand() % 100);
    cout<<"ilosc:" <<s.size();
    return 0;
}
