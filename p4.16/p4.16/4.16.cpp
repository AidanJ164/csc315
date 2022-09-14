#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;

    tree.insert(4);
    tree.insert(5);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    
    tree.remove(2);
    tree.remove(3);

    cout << "Min: " << tree.findMin() << endl;

    tree.remove(5);
    cout << "Max: " << tree.findMax() << endl;

    tree.insert(5);
    cout << "Max after insert: " << tree.findMax() << endl;

    cout << "Contains 4: " << tree.contains(4) << endl;
    cout << "Contains 2: " << tree.contains(2) << endl;
    return 0;
}
