#include <list>
#include <iostream>
using namespace std;

list<int> intersection(const list<int> & l1, const list<int> & l2);
list<int> lUnion(const list<int> & l1, const list<int> & l2);

int main()
{
    list<int> l1 = { 2, 4, 6 };
    list<int> l2 = { 1, 3, 5, 7 };
    list<int> intersect;
    list<int> u;
    auto itr = intersect.begin();

    intersect = intersection(l1, l2);
    cout << "Intersection of L1 and L2 is { ";
    for (itr = intersect.begin(); itr != intersect.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << "}" << endl;

    u = lUnion(l1, l2);
    cout << "Union of L1 and L2 is { ";
    for (itr = u.begin(); itr != u.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << "}" << endl;

    return 0;
}

list<int> intersection(const list<int> & l1, const list<int> & l2)
{
    list<int> l;
    auto itr = l1.begin();
    auto itr2 = l2.begin();

    for (itr = l1.begin(); itr != l1.end(); itr++)
    {
        for (itr2 = l2.begin(); itr2 != l2.end(); itr2++)
        {
            if (*itr == *itr2)
            {
                l.push_back(*itr);
            }
        }
    }

    return l;
}

list<int> lUnion(const list<int> & l1, const list<int> & l2)
{
    list<int> l = l1;
    auto itr = l2.begin();
    auto itr2 = l.begin();
    bool inList = false;

    for (itr = l2.begin(); itr != l2.end(); itr++)
    {
        for (itr2 = l.begin(); itr2 != l.end(); itr2++)
        {
            if (*itr == *itr2)
            {
                inList = true;
            }
            else if (*itr < *itr2 && inList == false)
            {
                l.insert(itr2, *itr);
                inList = true;
            }
        }
        if (inList == false)
        {
            l.push_back(*itr);
        }
        inList = false;
    }

    return l;
}
