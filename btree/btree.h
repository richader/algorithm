//二叉树的c++实现。简单练习。
//

#ifndef EXERCISE_BTREE_BTREE_H_
#define EXERCISE_BTREE_BTREE_H_

namespace exercise{
namespace btree{

class BTree;
class Node{
public:
    Node(const int val):val_(val){};
private:
    friend class BTree;
    Node* left;
    Node* right;
    int val_;
};

class BTree{
public:
    BTree();
    ~BTree();
    bool Insert(const int val);
    Node* Find(const int val);
    Node* GetMinValue();
    Node* GetMaxValue();
private:
    //递归删除二叉树，为减少函数调用，传入的参数不能为空。
    void DeleteTree(Node* node);
    Node* root_;
};
}
}

#endif //EXERCISE_BTREE_BTREE_H_
