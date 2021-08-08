#ifndef ZXHASH_H
#define ZXHASH_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
//===============================================
struct dict{
    string key;
    string value;
    dict():key(""),value(""){};
    dict(string Key,string Value):key(Key),value(Value){};
};
class ZxHash{
    private:
        int size;
        int num_data;
        vector < list< dict > > table;
        int PreHashing(string key_str);
        int HashFunction(string key_str);
    public:
        ZxHash():size(0),num_data(0),table(0){};
        ZxHash(int TableSize):size(TableSize),num_data(0){
            table.resize(TableSize);
        };
        void Insert(dict data);  
        void Delete(string key_str);
        string Search(string key_str);
        void DisplayTable();
};

#endif //ZXHASH_H