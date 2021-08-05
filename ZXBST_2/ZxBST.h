#ifndef ZXBST_H
#define ZXBST_H
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class TreeNode{
private:
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int key;
    string element;
public:
    TreeNode():left(0),right(0),parent(0),key(0),element(""){};
    TreeNode(int a, string b):left(0),right(0),parent(0),key(a),element(b){};
    int GetKey(){return key;}              
    string GetElement(){return element;}  
    friend class ZxBST; 
};
class ZxBST{
private:
    TreeNode* root;
    TreeNode* Leftmost(TreeNode *current);
    TreeNode* Successor(TreeNode *current);
public:
    ZxBST():root(0){};    
    TreeNode* Search(int key);
    void InsertBST(int key, string element);
    void InorderPrint(); 
    void Levelorder();  
    void DeleteBST(int key); 
      
};
#endif //ZxBST_H