#include "btree.h"

#include <queue>
#include <iostream>

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

bool BTree::IsComplete(){
    std::queue<Node*> nQueue;
    if(root_ == nullptr){
        return true;
    }

    nQueue.push(root_);
    Node* tmp=nullptr;
    bool leaf=false;
    do{
        tmp=nQueue.front();
        nQueue.pop();

        if((tmp->left == nullptr) && (tmp->right!=nullptr)){
            return false;
        }

        if(leaf && (tmp->left != nullptr || tmp->right != nullptr)){
            return false;
        }

        if(tmp->left==nullptr){
            leaf = true;
        }else if(tmp->right == nullptr){
            leaf = true;
        }

        if(tmp->left) nQueue.push(tmp->left);
        if(tmp->right) nQueue.push(tmp->right);
    }while(nQueue.size()>0);
    return true;
}

void BTree::PrintTree(){
    int deep=GetDeep(root_);
    std::queue<Node*> nQueue;
    if(root_ == nullptr){
        return;
    }

    nQueue.push(root_);

    Node* tmp = nullptr;

    for(int level=0;level<deep;++level){
        int size=nQueue.size();
        for(int i=0;i<size;++i){
            std::cout<<level<<","<<i<<":";
            tmp = nQueue.front();
            if(tmp !=nullptr){
                std::cout<<tmp->val_;
                nQueue.push(tmp->left);
                nQueue.push(tmp->right);
            }else{
                std::cout<<"null";
                nQueue.push(nullptr);
                nQueue.push(nullptr);
            }
            std::cout<<std::endl;
            nQueue.pop();
        }
        std::cout<<std::endl;
    }
}

int BTree::GetDeep(Node* node){
    if(node == nullptr){
        return 0;
    }

    int ldeep=GetDeep(node->left);
    int rdeep=GetDeep(node->right);
    return 1+(ldeep>rdeep?ldeep:rdeep);
}

}
}