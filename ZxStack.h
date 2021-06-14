#ifndef ZXSTACK_H
#define ZXSTACK_H
template <class T>
class ZxStack{
    private:
    struct Node{
        T value;
        Node* next;
        Node* pre;
    };
    //===========================================
    int size;
    Node* pHead;
    Node* pTail;
    //===========================================
    public:

    ZxStack();
    ~ZxStack();
    T pop();
    void push(T item);
    bool IsEmpty();
    int get_size();
};
#include "ZxStack.cpp"
#endif //ZXSTACK_H