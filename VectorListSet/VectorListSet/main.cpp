#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
using namespace std;

int main()
{
    list<int> l;
    vector<int> v;
    set<int> s;
    int i;
    int temp;

    auto start = chrono::high_resolution_clock::now();
    for (i = 0; i < 1000; i++)
    {
        l.push_back(rand() % 1000);
    }
    for (i = 0; i < 1000; i++);
    {
        l.remove(rand() % 1000);
    }
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    
    cout << "List took " << duration.count() << " microseconds." << endl;

    start = chrono::high_resolution_clock::now();
    for (i = 0; i < 1000; i++)
    {
        v.push_back(rand() % 1000);
    }

    auto itr = v.begin();
    for (i = 0; i < 1000; i++)
    {
        temp = rand() % 1000;
        while (itr != v.end() && *itr != temp)
        {
            itr++;
        }
        if (itr != v.end())
        {
            if (*itr == temp)
            {
                v.erase(itr);
            }
        }
    }
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Vector took " << duration.count() << " microseconds." << endl;

    start = chrono::high_resolution_clock::now();
    for (i = 0; i < 1000; i++)
    {
        s.insert(rand() % 1000);
    }
    for (i = 0; i < 1000; i++)
    {
        s.erase(rand() % 1000);
    }
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Set took " << duration.count() << " microseconds." << endl;

    return 0;
}
