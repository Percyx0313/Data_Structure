#include "ZxHeap.h"
#include <vector>
#include "iostream"
using namespace std;
void ZxHeap::swap(HeapNode & node1,HeapNode &node2){
    struct HeapNode temp=node1;
    node1=node2;
    node2=temp;
}
//===============================================
int ZxHeap::findposition(int node){
    for(int i=1;i<=heap.size();i++){
        if(heap[i].element==node){
            return i;
        }
    }
    return 0;
}
//===============================================
void ZxHeap::MinHeapify(int node, int length){
    int left=node*2;
    int right=node*2+1;
    int smallest=node;
    if(left<=length && heap[left].key > heap[node].key)
        smallest=left;
    if(right<=length && heap[right].key > heap[node].key)
        smallest=right;
    if(smallest!=node){
        swap(heap[smallest],heap[node]);
        MinHeapify(smallest,length);
    }
}
//===============================================
//by bottom-up
void ZxHeap::BuildMinHeap(std::vector<int> array){
    heap.resize(array.size()+1);
    for(int i=0;i<array.size();i++){
        heap[i+1].element=i;
        heap[i+1].key=array[i];
    }
    for(int i=heap.size()/2;i>1;i++){
        MinHeapify(i,heap.size()-1);
    }
}
//===============================================
void ZxHeap::DecreaseKey(int node, int newKey){
    int newnode=findposition(node);
    if(newnode==0){
        cout << "no this node" <<endl;
    }
    if(heap[newnode].key<newKey){
        std::cout << "new key is larger than current key\n";
        return;
    }
    while(newnode>1 && heap[GetParent(newnode)].key > heap[newnode].key){
        swap(heap[GetParent(newnode)],heap[newnode]);
        newnode=GetParent(newnode);
    }
}
//===============================================
void ZxHeap::MinHeapInsert(int node, int key){
    heap.push_back(HeapNode(node,key));
    DecreaseKey(node,key);
}
//===============================================
int ZxHeap::Minimum(){
    return heap.at(1).key;
}               
//===============================================  
int ZxHeap::ExtractMin(){
    if(IsHeapEmpty()){
        std::cout << "error: heap is empty\n";
        exit(-1);
    }
    int min=heap[1].element;
    heap[1]=heap[heap.size()-1];
    heap.erase(heap.begin()+heap.size()-1);
    MinHeapify(1,heap.size()-1);
    return min;
}