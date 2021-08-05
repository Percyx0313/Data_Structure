#include "ZxQueue.h"

template <class T>
ZxQueue<T>::ZxQueue(){
    pHead= new Node[1];
    pHead->next=NULL;
    pHead->pre=NULL;
    pTail=pHead;
    size=0;
}
/////////////////////////////////////////////////
template <class T>
ZxQueue<T>::~ZxQueue(){
    for(int i=0;i<size;i++){
        pop_front();
        size++;
    }
    delete pHead;
}
/////////////////////////////////////////////////
template <class T>
T ZxQueue<T>::front(){
    if(pHead==pTail) return pHead->value;
    else return pHead->next->value;
}
/////////////////////////////////////////////////
template <class T>
T ZxQueue<T>::back(){
    return pTail->value;
}
/////////////////////////////////////////////////
template <class T>
int ZxQueue<T>::get_size(){
    return size;
}
/////////////////////////////////////////////////
template <class T>
bool ZxQueue<T>::IsEmpty(){
    if(size==0) return true;
    else return false;
}
/////////////////////////////////////////////////
template <class T>
T ZxQueue<T>::pop_front(){
    if(pHead==pTail){
        return pHead->value;
    }
    else{
        size--;
        Node* remove;
        T value;
        remove=pHead->next;
        value=remove->value;
        if(remove==pTail){
            pTail=pHead;
            pHead->next=NULL;
        }else{
            pHead->next=remove->next;
            pHead->next->pre=pHead;
        }
        delete remove;
        return value;
    }
}
/////////////////////////////////////////////////
template <class T>
void ZxQueue<T>::push(T item){
    size++;
    if(pHead==pTail){
        pHead->next = new Node[1];
        pTail=pHead->next;
        pTail->next=NULL;
        pTail->pre=pHead;
    }
    else{
        pTail->next = new Node[1];
        pTail->next->pre=pTail;
        pTail=pTail->next;
        pTail->next=NULL;
    }
    pTail->value=item;
}