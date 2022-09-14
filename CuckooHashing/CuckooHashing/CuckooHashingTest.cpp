#include "CuckooHashing.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    CuckooHashTable ht(101);
    int i, temp;
    bool inTable;

   // srand(time(NULL));

    for (i = 0; i < 50; i++)
    {
        temp = rand() % 1000;
        while (ht.contains(temp))
            temp = rand() % 1000;
        cout << setw(5) << temp << ": " << ht.insert(temp) << endl;
    }
    
    cout << endl;

    for (i = 0; i < 50; i++)
    {
        temp = rand() % 1000;
        inTable = ht.contains(temp);
        if (inTable)
            cout << setw(5) << temp << ": True" << endl;
        else
            cout << setw(5) << temp << ": False" << endl;
    }
    cout << endl;
    ht.print();

    return 0;
}