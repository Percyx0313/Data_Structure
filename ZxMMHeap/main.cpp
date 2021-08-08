#include "iostream"
#include "ZxMMHeap.h"

using namespace std;
int main(){
    ZxMMHeap H;        
    int arr[13]={2,30,90,5,8,14,16,20,10,13,27,60,80};
    for(int i=0;i<13;i++){
        H.insert(arr[i],arr[i]);
    }
    H.ShowLevelOrder();
    cout << H.ExtractMax() <<endl;
    H.ShowLevelOrder();
    cout << H.ExtractMax() <<endl;
    H.ShowLevelOrder();


    return 0;
}