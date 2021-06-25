#include <iostream>
#include <string>
#include "ZxBST.h"
#include "ZxQueue.h"
using namespace std;
/////////////////////////////////////////////////
template <class T>
ZxBST<T>::ZxBST(){
    data=NULL;
    right=NULL;
    left=NULL;
}
/////////////////////////////////////////////////
template <class T>
ZxBST<T>::~ZxBST(){
    if(left!=NULL) delete [] left;
    if(right!=NULL) delete [] right;
    delete [] data;
}
/////////////////////////////////////////////////
template <class T>
T* ZxBST<T>::get_root(){
    return data;
}
/////////////////////////////////////////////////
template <class T>
int ZxBST<T>::get_size(){
    if(data==NULL) return 0;
    else if(!(right||left))
        return 1;
    else if(right&&(!left))
        return 1+right->get_size();
    else if((!right)&&left)
        return 1+left->get_size();
    else 
        return 1+right->get_size()+left->get_size();
}
/////////////////////////////////////////////////
template <class T>
bool ZxBST<T>::IsEmpty(){
    if(data==NULL)
        return true;
    else
        return false;
}
/////////////////////////////////////////////////
template<class T>
ZxBST<T>* ZxBST<T>::get_left(){
    return left;
}
/////////////////////////////////////////////////
template<class T>
ZxBST<T>* ZxBST<T>::get_right(){
    return right;
}
/////////////////////////////////////////////////
template <class T>
ZxBST<T>* ZxBST<T>::insert(T& value){
    if(data==NULL){
        data=new T;
        *data=value; 
        right=NULL;
        left=NULL;
        return this;
    }
    if(value<*data){
        if(left==NULL) left=new ZxBST[1];
        left->insert(value);
    }
    else if(value>*data){
        if(right==NULL) right=new ZxBST[1];
        right->insert(value);
    }
    return this;
}
/////////////////////////////////////////////////
template <class T>
void ZxBST<T>::remove(T& value){
    ZxBST*ptr,*pre;
    ptr=this;
    if((ptr->data)==NULL)return;
    while(*(ptr->data)!=value){
        if(*(ptr->data)<value){
            pre=ptr;
            ptr=ptr->right;
        }
        else if(*(ptr->data)>value){
            pre=ptr;
            ptr=ptr->left;
        }
        if(ptr==NULL) return;
    }
    if(ptr->right==NULL&&ptr->left==NULL){
        if(ptr==this){
            delete [] ptr->data;
            ptr->data=NULL;
            return;
        }
        if(pre->left==ptr){
            delete [] pre->left;
            pre->left=NULL;
        }
        else{
            delete [] pre->right;
            pre->right=NULL;
        }
    }
    else if(ptr->right==NULL&&ptr->left!=NULL){
        if(pre->left==ptr){
            pre->left=ptr->left;
            ptr->left=NULL;
            ptr->right=NULL;
            delete [] ptr;
        }
        else{
            pre->right=ptr->left;
            ptr->left=NULL;
            ptr->right=NULL;
            delete [] ptr;
        }
    }
    else if(ptr->right!=NULL&&ptr->left==NULL){
        if(pre->left==ptr){
            pre->left=ptr->right;
            ptr->left=NULL;
            ptr->right=NULL;
            delete [] ptr;
        }
        else{
            pre->right=ptr->right;
            ptr->left=NULL;
            ptr->right=NULL;
            delete [] ptr;
        }
    }else{
        T ch_source;
        ZxBST* ch_node=ptr->left;
        while(ch_node->right!=NULL){
            ch_node=ch_node->right;
        }
        ch_source=*(ch_node->data);
        remove(ch_source);
        *(ptr->data)=ch_source;
    }    
}
/////////////////////////////////////////////////
template <class T>
ZxBST<T>*  ZxBST<T>::find(T& value){
    if(data==NULL){
        return NULL;
    }
    if(*data==value) return this;
    else if(*data>value){
        if(left==NULL) return left;
        return left->find(value);
    }
    else if(*data<value){
        if(right==NULL) return right;
        return right->find(value);
    }
    return this;
}
/////////////////////////////////////////////////
template<class T>
void ZxBST<T>::show_preorder(){
    if(data==NULL) return;
    cout << *data << " ";
    if(left!=NULL)
        left->show_preorder();
    if(right!=NULL)
        right->show_preorder();
}
/////////////////////////////////////////////////
template<class T>
void ZxBST<T>::show_inorder(){
    if(data==NULL) return;
    if(left!=NULL)
        left->show_inorder();
    cout << *data <<" ";
    if(right!=NULL)
        right->show_inorder();
}
/////////////////////////////////////////////////
template<class T>
void ZxBST<T>::show_postorder(){
    if(data==NULL)return ;
    if(left!=NULL)
        left->show_postorder();
    if(right!=NULL)
        right->show_postorder();
    cout << *data <<" ";
}
/////////////////////////////////////////////////
template<class T>
bool ZxBST<T>::IsStrict(){
    if(left==NULL && right==NULL) return true;
    else if((left==NULL)||(right==NULL))return false;
    else return (left->IsStrict())&&(right->IsStrict()); 
}
// /////////////////////////////////////////////////
template<class T>
int ZxBST<T>::get_hight(){
    if(data==NULL)return 0;
    if(left==NULL && right==NULL) return 1;
    else if(left==NULL&&right!=NULL)
        return 1+right->get_hight();
    else if(left!=NULL&&right==NULL)
        return 1+left->get_hight();
    else{
        int right_hight=right->get_hight();
        int left_hight=left->get_hight();
        return 1+((right_hight<left_hight)?left_hight:right_hight);
    }   
}
// /////////////////////////////////////////////////
template<class T>
int  ZxBST<T>::get_num_leaf(){
    if(left==NULL && right==NULL)
        return 1;
    else if(left==NULL&&right!=NULL)
        return right->get_num_leaf();
    else if(left!=NULL&&right==NULL)
        return left->get_num_leaf();
    else
        return left->get_num_leaf()+right->get_num_leaf();
}
// /////////////////////////////////////////////////
// template<class T>
// bool ZxBST<T>::IsFull(){

// }
// /////////////////////////////////////////////////
// template<class T>
// bool ZxBST<T>::IsComplete(){

// }
// /////////////////////////////////////////////////
template<class T>
bool ZxBST<T>::IsEqual(ZxBST& Tree){
    bool result=false;
    if(data==NULL && (Tree.data)==NULL)
        return true;
    if(Tree.data==NULL)
        return false;
    if((*data)==(*(Tree.data))){
        result=true;
        if((left==NULL)==(Tree.left==NULL)){
            if((left!=NULL)&&(Tree.left!=NULL)){
                result=result*(left->IsEqual(*(Tree.left)));
            }
        }else{
            result=false;
        }
        if((right==NULL)==(Tree.right==NULL)){
            if((right!=NULL)&&(Tree.right!=NULL)){
                result=result*(right->IsEqual(*(Tree.right)));
            }
        }else{
            result=false;
        }
    }
    return result;    
}
// /////////////////////////////////////////////////
template<class T>
void ZxBST<T>::swap(){
    if(right==NULL&&left==NULL)return;
    ZxBST* temp;
    right->swap();
    left->swap();
    temp=right;
    right=left;
    left=temp;
}
// /////////////////////////////////////////////////
template<class T>
ZxBST<T>& ZxBST<T>::operator=(ZxBST<T>& Tree){
    if(left!=NULL)
        delete left;
    if(right!=NULL)
        delete right;
    if(data!=NULL)
        delete data;
    if(Tree.data!=NULL){
        data=new T[1];
        *data=*(Tree.data);
    }
    if(Tree.left!=NULL){
        left=new ZxBST[1];
        *left=*(Tree.left);
    }
    if(Tree.right!=NULL){
        right=new ZxBST[1];
        *right=*(Tree.right);
    }
    return *this;
}
////////////////////////////////////////////////////
template<class T>
bool ZxBST<T>::IsFull(){
    int size=get_size();
    int hight=get_hight();
    int max_num_node=1;
    while(hight!=1){
        max_num_node*=2;
    }
    max_num_node++;
    if(max_num_node!=size){
        return false;
    }
    else   return true;
}
// /////////////////////////////////////////////////
template<class T>
void ZxBST<T>::show_levelorder(){
    ZxQueue< ZxBST<T>* > queue;
    ZxBST<T>* current=this;
    queue.push(this);
    while(current->data!=NULL){
        if(current->left!=NULL) queue.push(current->left);
        if(current->right!=NULL) queue.push(current->right);
        if(queue.IsEmpty())return;
        cout << *(queue.pop_front()->data) <<" ";
        current=queue.front();
        if(queue.IsEmpty())return;
    }
}