#include "probing.h"
#include <iostream>
using namespace std;

int main()
{
    int i, j, temp, num_entries;
    int n = 50;
    double avg = 0;

    srand(time(NULL));

    for (j = 0; j < 100; j++)
    {
        hashTable table(101);

        for (i = 0; i < n; i++)
        {
            temp = rand() % 1000;
            while (table.contains(temp))
                temp = rand() % 1000;
            num_entries = table.insert(temp);
        }
        avg += num_entries;
    }

    avg = avg / 100;
    cout << avg;
        
    return 0;
}