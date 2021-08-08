#include "ZxMMHeap.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//===============================================
void ZxMMHeap::swap(HeapNode* h1,HeapNode* h2){
    HeapNode temp;
    temp.element=h1->element;
    temp.key=h1->key;
    h1->element=h2->element;
    h1->key=h2->key;
    h2->element=temp.element;
    h2->key=temp.key;
}
//===============================================
int ZxMMHeap::FindPosition(int node){
    for(int i=1;i<=Heap.size();i++){
        if(Heap[i]->element==node)
            return i;
    }
    return 0;
}
//===============================================
bool ZxMMHeap::WhichLevel(int index){
    if(index >0){
        if(index==1){
            return true;
        }
        int exp=1;
        int sum=0;
        int Level=0;
        while(index>sum){
            exp*=2;
            sum=exp-1;
            Level++;
        }
        return Level%2;
    }
    return false;
}
//===============================================
void ZxMMHeap::VerifyMax(HeapNode* node,int Index){
    int GrandPa=GetParent(GetParent(Index));
    while(GrandPa>0){
        if(Heap[GrandPa]->key>=Heap[Index]->key){
            return ;
        }else{
            swap(Heap[GrandPa],Heap[Index]);
            Index=GrandPa;
            GrandPa=GetParent(GetParent(Index));
        }
    }
}
//===============================================
void ZxMMHeap::VerifyMin(HeapNode* node,int Index){
    int GrandPa=GetParent(GetParent(Index));
    while(GrandPa>0){
        if(Heap[GrandPa]->key<=Heap[Index]->key){
            return ;
        }else{
            swap(Heap[GrandPa],Heap[Index]);
            Index=GrandPa;
            GrandPa=GetParent(GetParent(Index));
        }
    }
}
//===============================================
void ZxMMHeap::insert(int element,int key){
    HeapNode* node=new HeapNode(element,key);

    Heap.push_back(node);
    int index=Heap.size()-1;
    
    if(index>1){
        // min level
        if(WhichLevel(index)){
            if(Heap[index]->key <Heap[GetParent(index)]->key){
                VerifyMin(Heap[index],index);
            }
            else{
                swap(node,Heap[GetParent(index)]);
                index=GetParent(index);
                VerifyMax(node,index);
            }
        }
        // max level
        else{
            if(Heap[index]->key >Heap[GetParent(index)]->key){
                VerifyMax(Heap[index],index);
            }
            else{
                swap(node,Heap[GetParent(index)]);
                index=GetParent(index);
                VerifyMin(node,index);
            }
        }
    }
}
//===============================================
int ZxMMHeap::ExtractMin(){
    if(Heap.size()<=2){
        cout<< "There is no Node\n";
        return Heap[0]->element;
    }else{
        int value=Heap[1]->element;
        int current=1;
        int decendent=4;
        Heap[1]->element=Heap.back()->element;
        Heap[1]->key=Heap.back()->key;

        Heap.erase(Heap.begin()+Heap.size()-1);
        int MinNode=current;
        while(Heap.size()-1>=decendent && Heap.size()-1>=4){

            int min=0x7fffffff;
            
            for(int i=decendent;i<= ((decendent+3<=Heap.size()-1)?decendent+3:Heap.size()-1);i++){
                if(Heap[i]->key<min){
                    min=Heap[i]->key;
                    MinNode= i;
                }
            }

            if(Heap[current]->key<=Heap[MinNode]->key){
                return value;
            }
            swap(Heap[current],Heap[MinNode]);
            current=MinNode;
            decendent=current*4;
            if(current>1 && Heap[current]->key > Heap[GetParent(current)]->key ){
                swap(Heap[current],Heap[GetParent(current)]);
            }
            
        }
        MinNode=current;
        if(Heap.size()-1>=current*2){
            if(Heap[current*2]->key< Heap[MinNode]->key)
                MinNode=current*2;
        }   
        if(Heap.size()-1>=current*2+1){
            if(Heap[current*2+1]->key<Heap[MinNode]->key)
                MinNode=current*2+1;
        }
        swap(Heap[current],Heap[MinNode]);
        return value;
    }
}
//===============================================
int ZxMMHeap::ExtractMax(){
    if(Heap.size()<=2){
        cout<< "There is no Node\n";
        return Heap[0]->element;
    }else{
        int value=Heap[1]->element;
        int current=1;
        
        if(Heap.size()-1 >= 2){
            value=Heap[2]->element;
            current=2;
        }
        if(Heap.size()-1>=3){
            if(Heap[3]->key>value){
                value=Heap[3]->element;
                current=3;
            }
        }
        int decendent=current*4;
        Heap[current]->element=Heap.back()->element;
        Heap[current]->key=Heap.back()->key;

        Heap.erase(Heap.begin()+Heap.size()-1);
        int MaxNode=current;
        while(Heap.size()-1>=decendent && Heap.size()-1>=4){

            int max=0x80000000;
            
            for(int i=decendent;i<= ((decendent+3<=Heap.size()-1)?decendent+3:Heap.size()-1);i++){
                if(Heap[i]->key>max){
                    max=Heap[i]->key;
                    MaxNode= i;
                }
            }

            if(Heap[current]->key>=Heap[MaxNode]->key){
                return value;
            }
            swap(Heap[current],Heap[MaxNode]);
            current=MaxNode;
            decendent=current*4;
            if(current>1 && Heap[current]->key < Heap[GetParent(current)]->key ){
                swap(Heap[current],Heap[GetParent(current)]);
            }
            
        }
        MaxNode=current;
        if(Heap.size()-1>=current*2){
            if(Heap[current*2]->key> Heap[MaxNode]->key)
                MaxNode=current*2;
        }   
        if(Heap.size()-1>=current*2+1){
            if(Heap[current*2+1]->key>Heap[MaxNode]->key)
                MaxNode=current*2+1;
        }
        swap(Heap[current],Heap[MaxNode]);
        return value;
    }
}
//===============================================
int ZxMMHeap::Minimum(){
    if(Heap.size()==1){
        cout << "three is no node\n";
        return Heap[0]->element;
    }
    return Heap[1]->element;
}
//===============================================
int ZxMMHeap::MaxiMun(){
    if(Heap.size()==1){
        cout << "three is no node\n";
        return Heap[0]->element;
    }
    else if(Heap.size()==2){
        return Heap[1]->element;
    }else{
        if(Heap[2]->element>Heap[3]->element)
            return Heap[2]->element;
        else
            return Heap[3]->element;
    }
}
//===============================================
void  ZxMMHeap::ShowLevelOrder(){
    for(int i=1;i<Heap.size();i++){
        cout << Heap[i]->element <<" ";
    }
    cout << endl;
}
