#include <iostream>
#include <iomanip>
#include "vector.h"
using namespace std;

int main()
{
    Vector<int> v1(10);
    const int x = 5;
    auto itr = v1.begin();

    for( itr = v1.begin(); itr != v1.end(); itr++ )
    {
        *itr = rand() % 50;
        cout << *itr << " ";
    }
   
    const Vector<int> v3(v1);
    
    v3[5];

    Vector<int> v2(v1);

    v2 = v1;

    v1.push_back(x);
    v1.push_back(10);

    v1.back();
    
    v1.pop_back();

    v1.size();
    v1.capacity();

    v1.reserve(20);

    v1.resize(15);

    v1[5];
    
    auto itr2 = v3.begin();
    itr2 = v3.end();

    return 0;
}
