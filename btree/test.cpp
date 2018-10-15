#include "btree.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    using namespace exercise::btree;
    BTree tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);

    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);

    cout<< "Find 3 should be true:" << (tree.Find(3) != nullptr)<<endl;
    cout<< "Find 6 should be false:" << (tree.Find(6) != nullptr)<<endl;
    cout<< "min value is:"<< tree.GetMinValue()->GetValue()<<endl;
    cout<< "max value is:"<< tree.GetMaxValue()->GetValue()<<endl;
    return 0;
}
