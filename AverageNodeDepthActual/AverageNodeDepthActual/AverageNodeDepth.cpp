#include <iostream>
#include "BinarySearchTree.h"
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
    int n, i;
    int temp;
    BinarySearchTree<int> tree;
    
    n = 1600;

    for (i = 0; i < n; i++)
    {
        temp = rand() % 1000000;
        while (tree.contains(temp))
        {
            temp = rand() % 1000000;
        }
        tree.insert(temp);
    }

    cout << "Average depth of n=" << n << " is " << tree.avgDepth((double)n) << endl;
    cout << "log (" << n << ") = " << log2(n);
    return 0;
}