#ifndef ZXBST_H
#define ZXBST_H
struct TreeNode{
    struct TreeNode * left;
    struct TreeNode * right;
    struct TreeNode * parent;
    std::string str;
    TreeNode():left(0),right(0),parent(0),str(""){};
    TreeNode(std::string s):left(0),right(0),parent(0),str(s){};
    friend class ZxBST;
};
class ZxBST{
    public:
    struct TreeNode *root;
    ZxBST():root(0){};
    ZxBST(struct TreeNode* node):root(node){};
    ZxBST(const char * s);
    void LevelorderConstruct(std::stringstream &ss);
    void InsertLevelorder(char data);
    void PrintPreorder(struct TreeNode *CurrentNode);
    void PrintPostorder(struct TreeNode *CurrentNode);
    void PrintInorder(struct TreeNode *CurrentNode);
    void PrintLeveltorder();
    struct TreeNode* leftmost(struct TreeNode *current);
    struct TreeNode* rightmost(struct TreeNode *current);
    struct TreeNode* InorderSuccessor(struct TreeNode *CurrentNode);
    struct TreeNode* InorderPredessor(struct TreeNode *CurrentNode);
    void InorderByParent(struct TreeNode * root);
    void InorderReverse(struct TreeNode* root);
};
#endif //ZXBST_H