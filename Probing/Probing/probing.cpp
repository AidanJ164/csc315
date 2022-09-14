#include "probing.h"
#include <iostream>
using namespace std;

int main()
{
    hashTable table(53);
    int i, temp;

    for (i = 0; i < 25; i++)
    {
        int temp = rand() % 100;
        while (table.contains(temp))
        {
            temp = rand() % 100;
        }
        table.insert(temp);
    }

    cout << "First set of insertions:" << endl;
    table.print();

    for (i = 0; i < 25; i++)
    {
        temp = rand() % 100;
        table.remove(temp);
    }

    cout << endl << "After deletions:" << endl;
    table.print();
    
    for (i = 0; i < 25; i++)
    {
        int temp = rand() % 100;
        while (table.contains(temp))
        {
            temp = rand() % 100;
        }
        table.insert(temp);
    }

    cout << endl << "After another set of inserts: " << endl;
    table.print();

    return 0;
}