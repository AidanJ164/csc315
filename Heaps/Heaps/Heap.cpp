#include "BinaryHeap.h"
#include <iostream>
using namespace std;

int main()
{
    int i;
    BinaryHeap<int> heap(15);
    
    heap.insert(10);
    heap.insert(12);
    heap.insert(1);
    heap.insert(14);
    heap.insert(6);
    heap.insert(5);
    heap.insert(8);
    heap.insert(15);
    heap.insert(3);
    heap.insert(9);
    heap.insert(7);
    heap.insert(4);
    heap.insert(11);
    heap.insert(13);
    heap.insert(2);

    heap.printHeap();
    
    return 0;
}