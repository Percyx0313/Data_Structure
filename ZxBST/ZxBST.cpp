#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include "ZxBST.h"
//===============================================
void ZxBST::PrintPreorder(struct TreeNode *CurrentNode){
    if(CurrentNode){
        std::cout <<CurrentNode->str << " ";
        PrintPreorder(CurrentNode->left);
        PrintPreorder(CurrentNode->right);
    }
}
//===============================================
void ZxBST::PrintInorder(struct TreeNode *CurrentNode){
    if(CurrentNode){
        PrintInorder(CurrentNode->left);
        std::cout <<CurrentNode->str << " ";
        PrintInorder(CurrentNode->right);
    }
}
//===============================================
void ZxBST::PrintPostorder(struct TreeNode *CurrentNode){
    if(CurrentNode){
        PrintPostorder(CurrentNode->left);
        PrintPostorder(CurrentNode->right);
        std::cout <<CurrentNode->str << " ";
    }
}
//===============================================
void ZxBST::PrintLeveltorder(){
    std::queue<TreeNode*> queue;
    struct TreeNode * current;
    queue.push(root);
    while(!queue.empty()){
        current=queue.front();
        queue.pop();
        std:: cout << current->str << " ";
        if(current->left)
            queue.push(current->left);
        if(current->right)
            queue.push(current->right);

    }
}
//===============================================
struct TreeNode* ZxBST::leftmost(struct TreeNode *current){
    if(current){
        while(current->left)
            current=current->left;
    }
    return current;
}
//===============================================
struct TreeNode* ZxBST::rightmost(struct TreeNode *current){
    if(current){
        while(current->right)
            current=current->right;
    }
    return current;
}
//===============================================
struct TreeNode* ZxBST::InorderSuccessor(struct TreeNode *current){
    if(current){
        if(current->right)
            return leftmost(current->right);
        else{
            struct TreeNode* seccessor=current->parent;
            while(seccessor!=NULL && current!=seccessor->left){
                current=seccessor;
                seccessor=seccessor->parent;
            }
            return seccessor;
        }
    }
    return current;
}
//===============================================
void ZxBST::InorderByParent(struct TreeNode * root){
    struct TreeNode* CurrentNode=leftmost(root);
    if(CurrentNode){
        while(CurrentNode){
            std::cout << CurrentNode->str <<" ";
            CurrentNode=InorderSuccessor(CurrentNode);
        }
    }
}
//===============================================
struct TreeNode* ZxBST::InorderPredessor(struct TreeNode *CurrentNode){
    if(CurrentNode){
        if(CurrentNode->left)
            return rightmost(CurrentNode->left);
        else{
            struct TreeNode* Predessor=CurrentNode->parent;
            while(Predessor!=NULL && Predessor->left==CurrentNode){
                CurrentNode=Predessor;
                Predessor=Predessor->parent;
            }
            return Predessor;  
        }
    }
    return CurrentNode;
}
//===============================================
void ZxBST::InorderReverse(struct TreeNode* root){
    struct TreeNode* CurrentNode=rightmost(root);
    if(CurrentNode){
        while(CurrentNode){
            std::cout << CurrentNode->str <<" ";
            CurrentNode=InorderPredessor(CurrentNode);
        }
    }
}
//===============================================
void ZxBST::LevelorderConstruct(std::stringstream &ss){
    std:: queue<TreeNode*> queue;
    struct TreeNode * CurrentNode=root;
    char data='x';
    while(ss>>data){
        if(data>=65 && data<=90){
            struct TreeNode* NewNode=new TreeNode;
            NewNode->str= data;
            NewNode->parent=CurrentNode;
            CurrentNode->left=NewNode;
            queue.push(NewNode);
        }
        if(!(ss>>data)){
            break;
        }
        if(data>=65 && data<=90){
            struct TreeNode* NewNode=new TreeNode;
            NewNode->str= data;
            NewNode->parent=CurrentNode;
            CurrentNode->right=NewNode;
            queue.push(NewNode);
        }
        CurrentNode=queue.front();
        queue.pop();
    }   
}
//===============================================
ZxBST::ZxBST(const char * s){
    std::stringstream ss;
    ss<<s;
    root= new TreeNode;
    ss>> root->str;
    LevelorderConstruct(ss);
}