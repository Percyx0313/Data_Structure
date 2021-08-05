#include "ZxStack.h"

template <class T>
ZxStack<T>::ZxStack(){
    size=0;
    pHead = new Node[1];
    pTail=pHead;
    pHead->next=NULL;
    pHead->pre=NULL;
}
/////////////////////////////////////////////////
template <class T>
ZxStack<T>::~ZxStack(){
    for(int i=0;i<size;i++){
        pop();
        size++;
    }
    delete pHead;
}
/////////////////////////////////////////////////
template <class T>
T ZxStack<T>::pop(){
    if(pHead->next==NULL) return pHead->value;
    else{
        size--;
        Node* remove;
        T value;
        remove=pTail;
        value = remove->value;
        pTail=pTail->pre;
        pTail->next=NULL;
        delete remove;
        return value;
    }
}
/////////////////////////////////////////////////
template <class T>
bool ZxStack<T>::IsEmpty(){
    if(size==0) return true;
    else return false;
}
/////////////////////////////////////////////////
template <class T>
int ZxStack<T>::get_size(){
    return size;
}
/////////////////////////////////////////////////
template <class T>
void ZxStack<T>::push(T item){
    size++;
    if(pHead==pTail){
        pHead->next=new Node[1];
        pTail=pHead->next;
        pTail->pre=pHead;
        pTail->next=NULL;
    }else{
        pTail->next=new Node[1];
        pTail->next->pre=pTail;
        pTail=pTail->next;
        pTail->next=NULL;
    }
    pTail->value=item;
}
