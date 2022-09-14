#ifndef PROBING_H
#define PROBING_H

#include <vector>
#include <iostream>
using namespace std;

enum mark {
    ACTIVE, EMPTY, DELETED
};

class hashTable {
    public:
        hashTable(int size = 10)
        {
            tableSize = size;
            cell.resize(size);
        }
        ~hashTable() { }


        int findHash( int num )
        {
            return num % tableSize;
        }

        bool contains(int num)
        {
            int hash = findHash(num);

            while (cell[hash % tableSize].state != EMPTY && cell[hash % tableSize].num != num)
            {
                hash++;
            }
            if (cell[hash % tableSize].num == num)
                return true;

            return false;
        }

        int insert(int num)
        {
            if (contains(num))
                return 0;

            int probes = 1;
            int hash = findHash(num);

            while (cell[hash % tableSize].state == ACTIVE)
            {
                hash++;
                probes++;
            }

            cell[hash % tableSize].num = num;
            cell[hash % tableSize].state = ACTIVE;

            return probes;
        }

        bool remove(int num)
        {
            if (!contains(num))
                return false;

            int hash = findHash(num);

            while (cell[hash].state != EMPTY && cell[hash].num != num)
            {
                hash++;
            }
            if (cell[hash].num == num && cell[hash].state != DELETED)
            {
                cell[hash].state = DELETED;
                return true;
            }

            return false;
        }
        
        int size()
        {
            return tableSize;
        }
         

        void print()
        {
            int i;

            for (i = 0; i < tableSize; i++)
            {
                if (cell[i].state == ACTIVE)
                {
                    cout << i << ": " << cell[i].num << endl;
                }
            } 
        }


    private:
        struct data {
            int num = 0;
            mark state = EMPTY;
        };

        vector<data> cell;
        int tableSize;
};



#endif // !PROBING
