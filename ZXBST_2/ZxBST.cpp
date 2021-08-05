#include "ZxBST.h"
#include <iostream>
using namespace std;
//===============================================
TreeNode* ZxBST::Leftmost(TreeNode *current){
    if(current){
        while(current->left){
            current=current->left;
        }
    }
    return current;
}
//===============================================
TreeNode* ZxBST::Successor(TreeNode *current){
    if(current){
        if(current->right){
            return Leftmost(current->right);
        }
        else{
            TreeNode * Successor=current->parent;
            while(Successor!=NULL && Successor->left != current){
                current=Successor;
                Successor=Successor->parent;
            }
            return Successor;
        }
    }
    return current;
}
//===============================================
void ZxBST::InorderPrint(){
    TreeNode* current=Leftmost(root);
    if(current){
        while(current){
            cout<< current->element <<"("<<current->key<<") ";
            current=Successor(current);
        }
    }
}
//===============================================
void ZxBST::Levelorder(){
    TreeNode* current=root;
    queue<TreeNode*> queue;
    queue.push(current);
    while(!queue.empty()){
        current=queue.front();
        cout<< current->element <<"("<<current->key<<") ";
        queue.pop();
        if(current->left)
            queue.push(current->left);
        if(current->right)
            queue.push(current->right);
    }
}
//===============================================
TreeNode* ZxBST::Search(int key){
    TreeNode* current=root;
    while(current!=NULL && current->key!=key){
        if(key<current->key)
            current=current->left;
        else
            current=current->right;
    }
    return current;
}
//===============================================
void ZxBST::InsertBST(int key, string element){
    TreeNode *Current=0;
    TreeNode *CurrentParent=0;
    TreeNode *InsertNode=new TreeNode(key,element);
    Current=root;
    while(Current){
        CurrentParent=Current;
        if(Current->key<key)
            Current=Current->right;
        else
            Current=Current->left;
    }
    InsertNode->parent=CurrentParent;
    if(CurrentParent==NULL){
        root=InsertNode;
    }
    else if(key<CurrentParent->key)
        CurrentParent->left=InsertNode;
    else    
        CurrentParent->right=InsertNode;
}
//===============================================
void ZxBST::DeleteBST(int key){
    TreeNode *DeleteNode=Search(key);
    if(DeleteNode==NULL){
        cout << "data not found\n";
        return;
    }
    TreeNode *FreeNode;
    TreeNode *FreeChild;
    if(DeleteNode->left==NULL && DeleteNode->right==NULL)
        FreeNode=DeleteNode;
    else
        FreeNode=Successor(DeleteNode); 
    
    if(FreeNode->left!=NULL)
        FreeChild=FreeNode->left;
    else   
        FreeChild=FreeNode->right;
    

    if(FreeChild!=NULL){
        FreeChild->parent=FreeNode->parent;
    }
    if(FreeNode->parent==NULL){
        root=FreeChild;
    }
    else if(FreeNode->parent->left==FreeNode){
        FreeNode->parent->left=FreeChild;
    }else{
        FreeNode->parent->right=FreeChild;
    }
    if(FreeNode != DeleteNode){
        DeleteNode->key=FreeNode->key;
        DeleteNode->element=FreeNode->element;
    }
    delete  FreeNode;
} 