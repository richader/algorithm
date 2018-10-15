#include "btree.h"

namespace exercise{
namespace btree{

BTree::BTree():root_(nullptr){
}

BTree::~BTree(){
    if(root_){
        DeleteTree(root_);
    }
}

void BTree::DeleteTree(Node* node){
    //这里不做空值校验，否则每个空值位置都要进入函数才验证。
    //为了减少函数调用次数，函数外约束参数部为空。
    //这里是私有函数可以这样做，非私有函数部可以。
    if(node->left){
        DeleteTree(node->left);
    }
    if(node->right){
        DeleteTree(node->right);
    }

    delete node;
}

bool BTree::Insert(const int val){
    Node* node = new Node(val);
    if(node == nullptr){
        return false;
    }
    if(root_ == nullptr){
        root_=node;
        return true;
    }

    Node* tmp = root_;
    do{
        if(val <= tmp->val_){
            if(tmp->left){
                tmp=tmp->left;
                continue;
            }else{
                tmp->left = node;
                return true;
            }
        }else{
            if(tmp->right){
                tmp=tmp->right;
                continue;
            }else{
                tmp->right = node;
                return true;
            }
        }
    }while(true);
    return true;
}

Node* BTree::Find(const int val){
    Node* node = root_;
    while(node){
        if(node->val_ == val){
            return node;
        }else if(val < node->val_){
            node = node->left;
        }else{
            node = node->right;
        }
    }

    return nullptr;
}

Node* BTree::GetMaxValue(){
    Node* node = root_;
    while(node && node->right){
        node=node->right;
    }

    return node;
}

Node* BTree::GetMinValue(){
    Node* node = root_;
    while(node && node->left){
        node = node->left;
    }

    return node;
}


}
}