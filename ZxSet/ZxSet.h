#ifndef ZXSET_H
#define ZXSET_H
#include <iostream>
#include <iomanip>  
using namespace std;
int FindSetCollapsing(int* subset, int i){
    int root;
    for(root=i;subset[root]>=0;root=subset[root]);
    while(i!=root){
        int parent=subset[i];
        subset[i]=root;
        i=parent;
    }
    return root;
}
//===============================================
void UnionSet(int* subset,int x,int y){
    int root1=FindSetCollapsing(subset,x);
    int root2=FindSetCollapsing(subset,y);
    if(root1!=root2){
        // x's node more than y
        if(subset[root1]<=subset[root2]){
            subset[root1]+=subset[root2];
            subset[root2]=root1;
        }else{
            subset[root2]+=subset[root1];
            subset[root1]=root2;
        }
    }

}
//===============================================
void PrintArray(int *array, int size){
    for (int i = 0; i < size; i++){   
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++){   
        std::cout << std::setw(3) << array[i];
    }
    std::cout << std::endl;
}
#endif