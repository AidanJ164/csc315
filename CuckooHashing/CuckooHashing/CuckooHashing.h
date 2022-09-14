#ifndef CUCKOOHASHING_H
#define CUCKOOHASHING_H

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class CuckooHashTable
{
    public:
        CuckooHashTable(int size = 101)
        {
            table1.resize(size);
            table2.resize(size);
        }

        ~CuckooHashTable() {};

        bool contains(int num)
        {
            int index = hash1(num);
            int index2 = hash2(num);
            int index3 = backuphash(num);

            if (table1[index].element == num && table1[index].info == ACTIVE)
                return true;
            if (table2[index2].element == num && table2[index2].info == ACTIVE)
                return true;
            if (table1[index3].element == num && table1[index3].info == ACTIVE)
                return true;
            if (table2[index3].element == num && table2[index3].info == ACTIVE)
                return true;
            return false;
        }

        int insert(int num)
        {
            if (contains(num))
                return -1;

            int index = hash1(num);
            int evictions = 0;
            int temp;
            
            do
            {
                if (evictions % 10 == 0 && evictions != 0)
                    index = backuphash(num);
                if (table1[index].info != ACTIVE)
                {
                    table1[index].element = num;
                    table1[index].info = ACTIVE;
                    return evictions;
                }
                if (table1[index].info == ACTIVE && table2[hash2(table1[index].element)].info != ACTIVE)
                {
                    table2[hash2(table1[index].element)].element = table1[index].element;
                    table2[hash2(table1[index].element)].info = ACTIVE;

                    table1[index].element = num;
                    table1[index].info = ACTIVE;
                    evictions++;
                    return evictions;
                }
                if (evictions % 2 == 0)
                {
                    if (evictions % 10 != 0)
                        index = hash1(num);
                    temp = table1[index].element;
                    table1[index].element = num;
                    num = temp;
                    evictions++;
                }
                else
                {
                    if (evictions % 10 != 0)
                        index = hash2(num);
                    temp = table2[index].element;
                    table2[index].element = num;
                    num = temp;
                    evictions++;
                }
            } while (!contains(num));
            return evictions;
        }

        void print()
        {
            int i;
            for (i = 0; i < table1.size(); i++)
                if (table1[i].info == ACTIVE || table2[i].info == ACTIVE)
                    cout << setw(4) << i << ": " << setw(4) << table1[i].element << " | " << table2[i].element << endl;
        }

        int hash1(int num)
        {
            return num % table1.size();
        }

        int hash2(int num)
        {
            return (int)pow(num, 3.0) % table2.size();
        }

        int backuphash(int num)
        {
            return (int)sqrt(num) % table1.size();
        }

    private:
        enum mark
        {
            ACTIVE, EMPTY, DELETED
        };

        struct data
        {
            int element;
            mark info = EMPTY;
        };

        vector<data> table1;
        vector<data> table2;
};

#endif 
