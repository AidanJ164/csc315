#include "QuadraticProbing.h"
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
        HashTable<int> table(101);

        for (i = 0; i < n; i++)
        {
            temp = rand() % 1000;
            while (table.contains(temp))
            {
                temp = rand() % 1000;
            }
            num_entries = table.insert(temp);
        }
        avg += num_entries;
    }

    avg = avg / 100;
    cout << avg;

    return 0;
}


// AUTHOR'S FUNCTIONS NEEDED FOR CLASS

/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n <= 0 )
        n = 3;

    if( n % 2 == 0 )
        n++;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}

/**
 * A hash routine for string objects.
 */
int hash( const string & key )
{
    int hashVal = 0;

    for( int i = 0; i < key.length( ); i++ )
        hashVal = 37 * hashVal + key[ i ];

    return hashVal;
}

/**
 * A hash routine for ints.
 */
int hash( int key )
{
    return key;
}