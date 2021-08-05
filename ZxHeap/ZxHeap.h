#ifndef ZXHEAP_H
#define ZXHEAP_H
#include <vector>
struct HeapNode{
    int element;
    int key;
    HeapNode():element(0),key(0){};
    HeapNode(int node,int key):element(node),key(key){};
};
class ZxHeap{
    std::vector <HeapNode> heap;
    void swap(HeapNode & node1,HeapNode &node2);
    int findposition(int node);
    int GetParent(int node){return node/2;}
    public:
    ZxHeap(){heap.resize(1);}
    ZxHeap(int size){heap.resize(size+1);} 
    bool IsHeapEmpty(){return (heap.size()<1);};
    void MinHeapify(int node, int length);
    void BuildMinHeap(std::vector<int> array);
    void DecreaseKey(int node, int newKey);
    void MinHeapInsert(int node, int key);
    int Minimum();                 
    int ExtractMin();               
};
#endif //ZXHEAP_H