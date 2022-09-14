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
    
    n = 100;

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        temp = rand() % 1000000;
        while (tree.contains(temp))
        {
            temp = rand() % 1000000;
        }
        tree.insert(temp);
    }

    cout << "Average height of n=" << n << " is " << tree.avgHeight((double)n) << endl;
    cout << "log (" << n << ") = " << log(n);
    return 0;
}