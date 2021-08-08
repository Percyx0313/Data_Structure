#ifndef ZXRBT_H
#define ZXRBT_H
#include <iostream>
#include <string>
using namespace std;
class TreeNode{
    private:
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    string element;
    int key;
    bool color; //1 is black 1 is red
    friend class ZxRBT;
    TreeNode():left(0),right(0),parent(0),element(0),key(0),color(1){}; //default colore is red
    TreeNode(int Key,string Element):left(0),right(0),parent(0),element(Element),key(Key),color(1){};
};
class ZxRBT{
    private:
    TreeNode *root;
    TreeNode *neel;
    public:
    ZxRBT();
    void LeftRotation(TreeNode *node);
    void RightRotation(TreeNode *node);
    void InsertRBT(int key,string str);
    void InsertFixedUpRBT(TreeNode* CurrentNode);
    TreeNode* Search(int Key);
    void DeleteRBT(int Key);
    void DeleteFixUpRBT(TreeNode* CurrentNode);
    TreeNode* Successor(TreeNode* CurrentNode);
    TreeNode* LeftMost(TreeNode* CurrentNode);

};
#endif //ZxRBT_H