#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;

void fill( vector<int> & a );
int findk( const vector<int> & a, int k );
void sort( vector<int> & a );

int main()
{
    vector<int> a;
    int k;
    int i;

    cout << setw(15) << "kth Largest";
    cout << setw(15) << "# of Elements";
    cout << setw(15) << "ms to run" << '\n';

    for (i = 1000; i <= 5000; i += 1000)
    {
        // Start a timer to measure runtime.
        auto start = chrono::high_resolution_clock::now();

        a.resize(i);
        
        // Fill array with random elements.
        fill(a);

        // Find kth largest element with k = N/2.
        k = findk(a, (int)a.size() / 2);

        cout << setw(15) << k;

        auto stop = chrono::high_resolution_clock::now();

        // Find total runtime of algorithm
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << setw(15) << i;
        cout << setw(15) << duration.count() << '\n';
        a.clear();
    }

    return 0;
}

void fill( vector<int> & a )
{
    int i;

    for ( i = 0; i < a.size(); i++) 
    {
        a[i] = rand() % 10000;
    }
}

int findk( const vector<int> & a, int k )
{
    vector<int> b( k );
    int i, j;

    // Fill b with first k elements of a.
    for (i = 0; i < k; i++ )
    {
        b[i] = a[i];
    }
    
    sort( b );

    // Run through rest of elements.
    for (i = 0; i < a.size() - k; i++)
    {
        // Check to see if new element is larger than value at position k.
        if (a[k + i] > b[k - 1])
        {
            for (j = k - 1; j > 0; j--)
            {
                b[j] = b[j - 1];
            }

            b[0] = a[k + i];

            sort(b);
        }
    }

    return b[k - 1];
}

void sort( vector<int> & a )
{
    int i;
    int j;
    bool swapped;

    for ( i = 0; i < a.size() - 1; i++ )
    {
        swapped = false;
        for ( j = 0; j < a.size() - i - 1; j++ )
        {
            if ( a[j] < a[j + 1] )
            {
                swap( a[j], a[j + 1] );
                swapped = true;
            }
        }

        if (swapped == false)
        {
            return;
        }
    }
}
