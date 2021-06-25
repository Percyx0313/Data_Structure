// Todo: destructor and remove have some problem 
#ifndef ZXBST_H
#define ZXBST_H
template <class T>
class ZxBST{
    /////////////////////////////////////////////
    T* data;
    ZxBST<T>* left;
    ZxBST<T>* right;
    /////////////////////////////////////////////
    public:
    ///@brief constructor
    ZxBST();
    ///@brief destructor
    ~ZxBST();
    ///@brief determine whether this node is empty
    bool IsEmpty();
    ///@brief get the number of node
    int get_size();
    ///@brief get the pointer of root
    T* get_root();
    ///@brief get the pointer of right subtree
    ZxBST<T>* get_right();
    ///@brief get the pointer of left subtree
    ZxBST<T>* get_left();
    ///@brief determine whether the tree is strict tree
    bool IsStrict();
    ///@brief get height of the tree
    int get_hight();
    ///@brief get the total number of the leaves
    int  get_num_leaf();
    ///@brief determine this tree is full
    bool IsFull();
    // determine two pair tree is equal
    bool IsEqual(ZxBST<T>& Tree);
    ///@brief show the tree by preorder
    void show_preorder();
    ///@brief show the tree by inorder
    void show_inorder();
    ///@brief show the tree by postorder
    void show_postorder();
    ///@brief show the tree by levelorder
    void show_levelorder();
    ///@brief swap all subtrees left and right
    void swap();
    ///@brief insert the new node that not in the tree and return this node in the tree
    ZxBST<T>* insert(T& value);
    ///@brief find whether this node is in the tree and return this node in the tree if not return NULL
    ZxBST<T>* find(T& value);
    ///@brief remove the node with value T 
    void remove(T& value);
    ///@brief assign operation
    ZxBST<T>& operator=(ZxBST<T>& Tree);
};

#include "ZxBST.cpp"
#endif //ZXBST_H