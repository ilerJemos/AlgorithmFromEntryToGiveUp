#include "myLinkQueue.h"
// #include<iostream>
// using namespace std;

template <class T>
bool myLinkQueue<T>::Add(const T item)
{
    struct node *temp = new struct node;
    if (temp)
    {
        std::cout<<"添加元素："<<endl;
        temp->data = item;
        rear->link = temp;
        rear = temp;
        return true;
    }
    else
        return false;
}
template <class T>
bool myLinkQueue<T>::Delete(T &item)
{
    if (EmptyQueue()){
        // std::cout<<"队列已空"<<std::endl;
        return false;
    }
    else
    {
        struct node *temp;
        temp = front;
        front = front->link;
        item = front->data;
        // cout<<"删除元素:"<<item<<endl;
        delete temp;
        return true;
    }
}

// using namespace std;
// int main(){
//     myLinkQueue<int> l;
//     l.Add(1);
//     l.Add(2);
//     int d;
//     l.Delete(d);
//     std::cout<<d<<std::endl;
//     l.Delete(d);
//     std::cout<<d<<std::endl;
//     return 0;
// }