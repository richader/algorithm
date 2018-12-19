/*
	平衡二叉树实现
*/

#include "btree.h"


namespace exercise{
namespace btree{

class AvlTree;
class AvlNode :public Node {
	int degree;
};

class AvlTree : public BTree { 
public:
    bool Insert(const int val);
    void Delete(const int val);
 protected:
    Node* LRotate(Node* node);
    Node* RRotate(Node* node);
}; 

}
}