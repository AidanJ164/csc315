#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include <vector>
#include <iostream>
using namespace std;

class linearHashTable {
    public:
        linearHashTable(int size = 10)
        {
            table.resize(size);
        }
        ~linearHashTable() { }


        int findHash( int num )
        {
            return num % table.size();
        }

        bool contains(int num)
        {
            int hash = findHash(num);

            while (table[hash % table.size()].state != EMPTY && table[hash % table.size()].num != num)
            {
                hash++;
            }
            if (table[hash % table.size()].num == num)
                return true;

            return false;
        }

        bool insert(int num)
        {
            if (contains(num))
                return false;

            int hash = findHash(num);

            while (table[hash % table.size()].state == ACTIVE)
            {
                hash++;
            }

            table[hash % table.size()].num = num;
            table[hash % table.size()].state = ACTIVE;

            if (++currentSize > table.size() / 2)
                rehash();

            return true;
        }

        bool remove(int num)
        {
            if (!contains(num))
                return false;

            int hash = findHash(num);

            while (table[hash].state != EMPTY && table[hash].num != num)
            {
                hash++;
            }
            if (table[hash].num == num && table[hash].state != DELETED)
            {
                table[hash].state = DELETED;
                return true;
            }

            return false;
        }
        
        int size()
        {
            return table.size();
        }

        void print()
        {
            int i;

            for (i = 0; i < table.size(); i++)
            {
                if (table[i].state == ACTIVE)
                {
                    cout << i << ": " << table[i].num << endl;
                }
            } 
        }


    private:
        enum mark {
            ACTIVE, EMPTY, DELETED
        };

        struct data {
            int num = 0;
            mark state = EMPTY;
        };

        void rehash()
        {
            vector<data> oldArray = table;
            int i;

            table.resize(table.size() * 2);
            for (i = 0; i < table.size(); i++)
                table[i].state = EMPTY;

            currentSize = 0;
            for (i = 0; i < oldArray.size(); i++)
                if (oldArray[i].state == ACTIVE)
                    insert(oldArray[i].num);
        }

        vector<data> table;
        int currentSize = 0;
};
#endif // !PROBING
