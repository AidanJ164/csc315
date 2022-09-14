#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include <vector>
#include <iostream>
using namespace std;

int nextPrime( int n );

class doubleHashTable {
    public:
        doubleHashTable(int size = 10)
        {
            table.resize(nextPrime(size));
        }
        ~doubleHashTable() { }

        int findHash(int num)
        {
            return num % table.size();
        }

        int findSecondHash(int num)
        {
            return 7 - (num % 7);
        }

        bool contains(int num)
        {
            int hash = findHash(num);

            while (table[hash % table.size()].state != EMPTY && table[hash % table.size()].num != num)
            {
                hash += findSecondHash(num);
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
                hash += findSecondHash(num);
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
                hash += findSecondHash(num);
            }
            if (table[hash].num == num && table[hash].state != DELETED)
            {
                table[hash].state = DELETED;
                return true;
            }

            return false;
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

        vector<data> table;
        int currentSize;

        void rehash()
        {
            vector<data> oldArray = table;
            int i;

            table.resize( nextPrime(table.size() * 2) );
            for (i = 0; i < table.size(); i++)
                table[i].state = EMPTY;

            currentSize = 0;
            for (i = 0; i < oldArray.size(); i++)
                if (oldArray[i].state == ACTIVE)
                    insert(oldArray[i].num);
        }
};

#endif // !DOUBLEHASHING_H
