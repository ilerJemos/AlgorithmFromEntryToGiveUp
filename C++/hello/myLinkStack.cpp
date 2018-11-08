#include"myLinkStack.h"

template <class T> bool myLinkStack<T>::Add (const T item){
    struct node *temp = new node;
    if(temp){
        temp->data = item;
        temp->link = top;
        top = temp;
        return true;
    }
    else{
        //cout<<"out of space"<<endl;
        return false;
    }
}
template <class T> bool myLinkStack<T>::Delete(T& item){
    if(StackEmpty()){
        return false;
    }
    else{
        struct node *temp = new node;
        temp = top;
        top = temp->link;
        delete temp;
    }
}

// int main(){
//     myLinkStack<int> l;
//     l.Add(1);
//     l.Add(2);
//     //l.Delete();
//     return 0;
// }