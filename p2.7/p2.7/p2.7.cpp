#include <iostream>
#include <chrono>
#include <functional>
#include <iomanip>
using namespace std;

long long time(function <int(int)> alg, int n);
int alg1(int n);
int alg2(int n);
int alg3(int n);
int alg4(int n);
int alg5(int n);
int alg6(int n);

int main()
{
    int n;
    long long count;

    cout << setw(5) << "n"
         << setw(12) << "alg1" 
         << setw(12) << "alg2" 
         << setw(12) << "alg3"
         << setw(12) << "alg4" 
         << setw(12) << "alg5" 
         << setw(12) << "alg6" 
         << endl;
    for (n = 50; n <= 250; n += 50)
    {
        cout << setw(5) << n;

        count = time(alg1, n);
        cout << setw(12) << count;

        count = time(alg2, n);
        cout << setw(12) << count;

        count = time(alg3, n);
        cout << setw(12) << count;
        
        count = time(alg4, n);
        cout << setw(12) << count;
        
        count = time(alg5, n);
        cout << setw(12) << count;
        
        count = time(alg6, n);
        cout << setw(12) << count << endl;
    }

    return 0;
}

long long time(function <int(int)> alg, int n)
{
    int sum;
    auto start = chrono::high_resolution_clock::now();

    sum = alg(n);

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    return duration.count();
}

int alg1(int n)
{
    int sum = 0, i;
    
    for (i = 0; i < n; i++)
    {
        sum++;
    }

    return sum;
}

int alg2(int n)
{
    int sum = 0, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum++;
        }
    }

    return sum;
}

int alg3(int n)
{
    int sum = 0, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n * n; j++)
        {
            sum++;
        }
    }

    return sum;
}

int alg4(int n)
{
    int sum = 0, i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            sum++;
        }
    }

    return sum;
}

int alg5(int n)
{
    int sum = 0, i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i * i; j++)
        {
            for (k = 0; k < j; k++)
            {
                sum++;
            }
        }
    }

    return sum;
}

int alg6(int n)
{
    int sum = 0, i, j, k;

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < i * i; j++)
        {
            if (j % i == 0)
            {
                for (k = 0; k < j; k++)
                {
                    sum++;
                }
            }
        }
    }

    return sum;
}