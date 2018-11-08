#include "myQueue.h"
template <class T>
bool myQueue<T>::Add(T item)
{
    if (FullQueue())
    {
        //cout<<"the queue is full<<endl";
        return false;
    }
    else
    {
        queue[rear] = item;
        return true;
    }
}
template <class T>
bool myQueue<T>::Delete(T &item)
{
    if (EmptyQueue())
        return false;
    else
    {
        front = (front+1) % (MaxSize);
        item = queue[front];
        return true;
    }
}
#include<iostream>
int main(){
    myQueue<int> a(10);
    a.Add(10);
    a.Add(100);
    int b;
    a.Delete(b);
    std::cout<<b;
    return 0;
}