#include "SeparateChaining.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "DoubleHashing.h"
#include <iostream>
using namespace std;

bool isPrime(int n);

int main()
{
    HashTable ht(10);
    linearHashTable lht(10);
    quadraticHashTable qht(10);
    doubleHashTable dht(10);
    
    cout << "Separate Chaining Table: " << endl;
    ht.insert(4371);
    ht.insert(1323);
    ht.insert(6173);
    ht.insert(4199);
    ht.insert(4344);
    ht.insert(9679);
    ht.insert(1989);
    ht.print();

    cout << endl << "Linear Probing Table: " << endl;
    lht.insert(4371);
    lht.insert(1323);
    lht.insert(6173);
    lht.insert(4199);
    lht.insert(4344);
    lht.insert(9679);
    lht.insert(1989);
    lht.print();

    cout << endl << "Quadratic Probing Table: " << endl;
    qht.insert(4371);
    qht.insert(1323);
    qht.insert(6173);
    qht.insert(4199);
    qht.insert(4344);
    qht.insert(9679);
    qht.insert(1989);
    qht.print();
    
    cout << endl << "Double Probing Table: " << endl;
    dht.insert(4371);
    dht.insert(1323);
    dht.insert(6173);
    dht.insert(4199);
    dht.insert(4344);
    dht.insert(9679);
    dht.insert(1989);
    dht.print();

    return 0;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}

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
