#ifndef ZXQUEUE_H
#define ZXQUEUE_H
template <class T>
class ZxQueue{
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

    ZxQueue();
    ~ZxQueue();
    T pop_front();
    T back();
    T front();
    void push(T item);
    bool IsEmpty();
    int get_size();
};
#include "ZxQueue.cpp"
#endif //ZXQUEUE_H




