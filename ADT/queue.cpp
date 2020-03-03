#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>
using namespace std;

void add_elements(queue<int> *s, int m)
{
    int i = 0;

    while (i < m)
    {
        s->push(rand() % 100);
        i++;
    }
}
bool remove_elements(queue<int> *s, int k)
{
    int i = 0;
    while (i < k)
    {
        if (!s->empty())
        {
            s->pop();
            i++;
        }
        else
        {
            cout << "Mam blad" << endl;
            return false;
        }
    }
    return true;
}
void show_queue(queue<int> q)
{
    int i = 0;
    int num = q.size();
    while (!q.empty())
    {

        cout << i << " element is :" << q.front() << endl;
        q.pop();
        i++;
    }
}
queue<int> add_at_front(queue<int> *q, int elements)
{
    queue<int> Q;
    queue<int> *Q_pointer;
    Q_pointer = &Q;
    add_elements(Q_pointer, elements);
    while (!q->empty())
    {
        Q.push(q->front());
        q->pop();
    }

    return Q;
}
int main()
{
    queue<int> s;
    int i = 0;
    int queue_elements = 7;
    int queue_rm_elemets = 3;
    queue<int> *pointer;
    pointer = &s;

    add_elements(pointer, queue_elements);
    if(!s.empty())cout << "The front value from queue : " << s.front() << endl;

    remove_elements(pointer,queue_rm_elemets);
    add_elements(pointer,queue_elements);
   
    
    if(!s.empty())cout << "The front value from queue: " << s.front() << endl;
 
    cout << "ilosc:" << s.size();
    return 0;
}