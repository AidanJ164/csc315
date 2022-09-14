#ifndef HEAP_H
#define HEAP_H
#include <vector>
using namespace std;

class Heap {



    private:
        int currentSize;
        vector<int> array;

        void buildHeap();
        void percolateDown();
};

#endif