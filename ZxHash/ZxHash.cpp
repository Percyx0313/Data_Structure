#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "ZxHash.h"
using namespace std;
//===============================================
void ZxHash::Insert(dict data){
    int index=HashFunction(data.key);
    table[index].push_front(data);
}
//===============================================
void ZxHash::Delete(string key_str){
    int index=HashFunction(key_str);
    for(list<dict> :: iterator itr=table[index].begin();itr!=table[index].end();itr++){
        if((*itr).key==key_str){
            table[index].erase(itr);
        }
    }
}
//===============================================
string ZxHash::Search(string key_str){
    int index=HashFunction(key_str);
    for(list<dict> :: iterator itr=table[index].begin();itr!=table[index].end();itr++){
        if((*itr).key==key_str){
            return (*itr).value;
        }
    }
    return "no such data";
}
//===============================================
void ZxHash::DisplayTable(){
    for(int i=0;i<table.size();i++){
        cout << "slot#" << i << ": ";
        for(list<dict>::iterator itr=table[i].begin();itr!=table[i].end();itr++){
            cout << "(" <<(*itr).key << ","<<(*itr).value <<")";
        }
        cout<< endl;
    }
}
//===============================================
int ZxHash::PreHashing(string key_str){
    int exp=9;
    int key_int=0;
    int p=1;
    for(int i=key_str.size()-1;i>=0;i--){
        key_int+=key_str[i]*p;
        p*=exp;
    }
    return key_int;
}
//===============================================
int ZxHash::HashFunction(string key_str){
    return PreHashing(key_str)%this->size;
}
//===============================================