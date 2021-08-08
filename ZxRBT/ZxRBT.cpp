#include <iostream>
#include "ZxRBT.h"
//===============================================
ZxRBT::ZxRBT(){
    neel = new TreeNode;
    neel->color=0;
    root=neel;
}
//===============================================
void ZxRBT::LeftRotation(TreeNode *node){
    TreeNode* Rnode=node->right;
    node->right=Rnode->left;
    if(Rnode->left!=neel)
        Rnode->left->parent=node;
    Rnode->parent=node->parent;
    if(node->parent==neel){
        root=Rnode;
    }
    else if(node->parent->left==node)
        node->parent->left=Rnode;
    else
        node->parent->right=Rnode;
    
    Rnode->left=node;
    node->parent=Rnode;
}
//===============================================
void ZxRBT::RightRotation(TreeNode *node){
    TreeNode* Lnode=node->left;
    node->left=Lnode->right;
    if(Lnode->right!=neel)
        Lnode->right->parent=node;  
    
    Lnode->parent=node->parent;
    if(node->parent==neel){
        root=Lnode;
    }
    else if(node->parent->left==node)
        Lnode->parent->left=Lnode;
    else    
        Lnode->parent->right=Lnode;
    
    node->parent=Lnode;
    Lnode->right=node;
}
//===============================================
void ZxRBT::InsertRBT(int key,string str){
    TreeNode* insert_node=new TreeNode(key,str);
    TreeNode* CurrentNode=root;
    TreeNode* CurrentNodeParent=neel;
    while(CurrentNode!=neel){
        CurrentNodeParent=CurrentNode;
        if(CurrentNode->key<key)
            CurrentNode=CurrentNode->right;
        else
            CurrentNode=CurrentNode->left;
    }
    insert_node->parent=CurrentNodeParent;

    if(CurrentNodeParent==neel){
        root=insert_node;
    }
    else if(insert_node->key<CurrentNodeParent->key){
        CurrentNodeParent->left=insert_node;
    }else{
        CurrentNodeParent->right=insert_node;
    }
    insert_node->right=neel;
    insert_node->left=neel;
    insert_node->color=1; // 1 is red
    InsertFixedUpRBT(insert_node);
}
//===============================================
void ZxRBT::InsertFixedUpRBT(TreeNode* CurrentNode){
    while(CurrentNode->parent->color==1){
        //parent is grand parent left
        if(CurrentNode->parent==CurrentNode->parent->parent->left){
            TreeNode* UncleNode=CurrentNode->parent->parent->right;
            //case 1 : uncle is red
            if(UncleNode->color==1){
                CurrentNode->parent->color=0;
                UncleNode->color=0;
                UncleNode->parent->color=1;
                CurrentNode=UncleNode->parent;
            }
            //case 2 && case 3 : uncle is black
            else{
                if(CurrentNode==CurrentNode->parent->right){
                    CurrentNode=CurrentNode->parent;
                    LeftRotation(CurrentNode);
                }
                CurrentNode->parent->color=0;
                CurrentNode->parent->parent->color=1;
                RightRotation(CurrentNode->parent->parent);
            }
        }else{
            TreeNode* UncleNode=CurrentNode->parent->parent->left;
            if(UncleNode->color==1){
                CurrentNode->parent->color=0;
                UncleNode->color=0;
                UncleNode->parent->color=1;
                CurrentNode=UncleNode->parent;
            }
            //case 2 && case 3 : uncle is black
            else{
                if(CurrentNode==CurrentNode->parent->left){
                    CurrentNode=CurrentNode->parent;
                    RightRotation(CurrentNode);
                }
                CurrentNode->parent->color=0;
                CurrentNode->parent->parent->color=1;
                LeftRotation(CurrentNode->parent->parent);
            }
        }  
    }
    root->color=0;
}
//===============================================
TreeNode* ZxRBT::Search(int Key){
    TreeNode* CurrentNode=root;
    while(CurrentNode!=neel){
        if(CurrentNode->key==Key){
            return CurrentNode;
        }
        else if(CurrentNode->key<Key)
            CurrentNode=CurrentNode->right;
        else
            CurrentNode=CurrentNode->left;
    }
    return CurrentNode;
}
//===============================================
void ZxRBT::DeleteRBT(int Key){
    TreeNode *DeleteNode=Search(Key);
    if(DeleteNode==neel){
        std:: cout << "data not found\n";
        return ;
    }
    TreeNode *FreeNode=0;
    TreeNode *FreeNodeChild=0;
    if(DeleteNode->left==neel || DeleteNode->right == neel){
        FreeNode=DeleteNode;
    }    
    else{
        FreeNode=Successor(DeleteNode);
    }

    if(FreeNode->left==neel){
        FreeNodeChild=FreeNodeChild->right;
    }else{
        FreeNodeChild=FreeNodeChild->left;
    }

    FreeNodeChild->parent=FreeNode->parent;
    if(FreeNode->parent==root){
        root=FreeNode;
    }
    else if(FreeNode->parent->left=FreeNode){
        FreeNode->parent->left=FreeNodeChild;
    }else{
        FreeNode->parent->right=FreeNodeChild;
    }
    if(FreeNode!=DeleteNode){
        DeleteNode->key=FreeNode->key;
        DeleteNode->element=FreeNode->element;
    }
    if(FreeNode->color==0){
        DeleteFixUpRBT(FreeNodeChild);
    }
    delete FreeNode;
}
//===============================================
void ZxRBT::DeleteFixUpRBT(TreeNode* CurrentNode){
    // case 0 : Current red -> balck
    while(CurrentNode !=root  && CurrentNode->color==0){
        //left 
        if(CurrentNode==CurrentNode->parent->left){
            TreeNode* sibling=CurrentNode->parent->right;
            //case 1 : sibling color is red
            if(sibling->color==1){
                sibling->color=0;
                sibling->parent->color=1;
                LeftRotation(sibling->parent);
                sibling=CurrentNode->parent->right;
            }
            //case 2 : siblin and its children are black
            if(sibling->right->color==0 && sibling->left->color==0){
                sibling->color=1;
                CurrentNode=CurrentNode->parent;
            }else{
                //case 3 : right child is black left is red
                if(sibling->right->color==0){
                    sibling->color=1;
                    sibling->left->color=0;
                    LeftRotation(sibling);
                    sibling=CurrentNode->parent->right;
                }
                //case 4 : sibling black right red left black
                sibling->color=CurrentNode->parent->color;
                CurrentNode->parent->color=0;
                sibling->right->color=0;
                LeftRotation(CurrentNode->parent);
                break;
            }
        }else{
            TreeNode* sibling=CurrentNode->parent->left;
            //case 1 : sibling color is red
            if(sibling->color==1){
                sibling->color=0;
                sibling->parent->color=1;
                RightRotation(sibling->parent);
                sibling=CurrentNode->parent->left;
            }
            //case 2 : siblin and its children are black
            if(sibling->left->color==0 && sibling->right->color==0){
                sibling->color=1;
                CurrentNode=CurrentNode->parent;
            }else{
                //case 3 : right child is black left is red
                if(sibling->left->color==0){
                    sibling->color=1;
                    sibling->right->color=0;
                    LeftRotation(sibling);
                    sibling=CurrentNode->parent->left;
                }
                //case 4 : sibling black right red left black
                sibling->color=CurrentNode->parent->color;
                CurrentNode->parent->color=0;
                sibling->left->color=0;
                RightRotation(CurrentNode->parent);
                break;
            }
        
    }
    CurrentNode->color=0;
}
//===============================================
TreeNode* ZxRBT::Successor(TreeNode* CurrentNode){
    if(CurrentNode!=neel){
        if(CurrentNode->right!=neel){
            return LeftMost(CurrentNode->right);
        }
        else{
            TreeNode* Successor=CurrentNode->parent;
            while(Successor!=neel && Successor->left!=CurrentNode){
                CurrentNode=Successor;
                Successor=Successor->parent;
            }
            return Successor;
        }
    }
    return neel;
}
//===============================================
TreeNode* ZxRBT::LeftMost(TreeNode* CurrentNode){
    if(CurrentNode!=neel){
        TreeNode* LNode=CurrentNode;
        while(LNode->left!=neel){
            LNode=LNode->left;
        }
        return LNode;
    } 
    return neel;   
}