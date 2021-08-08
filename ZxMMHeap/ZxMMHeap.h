#ifndef ZXMMHEAP_H
#define ZXMMHEAP_H
#include <iostream>
#include <vector>
using namespace std;
class HeapNode{
    int element;
    int key;
    HeapNode():element(0),key(0){};
    HeapNode(int Element,int Key):element(Element),key(Key){};
    friend class ZxMMHeap;
};
class ZxMMHeap{
    private:
    std::vector<HeapNode*> Heap;
    void swap(HeapNode* h1,HeapNode* h2);
    int FindPosition(int node);
    int GetParent(int node){return node/2;}
    bool WhichLevel(int index); // 1 is Min 0 is Max
    void VerifyMax(HeapNode* node,int Index);
    void VerifyMin(HeapNode* node,int Index);
    public:
    ZxMMHeap(){
        Heap.resize(1);
    }
    ZxMMHeap(int size){
        Heap.resize(size+1);
    }

    void insert(int element,int key);
    int ExtractMin();
    int ExtractMax();
    int Minimum();
    int MaxiMun();
    void ShowLevelOrder();
};
#endif //ZXMMHEAP_H