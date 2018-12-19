#include "AvlTree.h"


namespace exercise{
namespace btree{

Node* AvlTree::LRotate(Node* node){
    Node* tmp = node->left;
    node->left = tmp->right;
    tmp->right=node;
    return tmp;
}

Node* AvlTree::RRotate(Node* node){
    Node* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    return tmp;
}

}
}