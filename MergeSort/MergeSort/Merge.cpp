#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> & v, int level);

int main()
{
    vector<int> v;
    int i, temp;

    for (i = 0; i < 20; i++)
        v.push_back(rand() % 100);

    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    mergeSort(v, 0);

    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}

void mergeSort(vector<int> & v, int level)
{
    if (v.size() == 1)
    {
        cout << "Layer: " << level << endl;
        return;
    }

    vector<int> left;
    vector<int> right;
    int i = 0, j = 0, lctr = 0, rctr = 0, cctr = 0;

    while (i != v.size() / 2)
    {
        left.push_back(v[i]);
        i++;
    }
    while (i < v.size())
    {
        right.push_back(v[i]);
        i++;
    }

    mergeSort(left, level + 1);
    mergeSort(right, level + 1);

    while (cctr < v.size())
    {
        if (lctr < left.size() && rctr < right.size())
        {
            if (left[lctr] < right[rctr])
            {
                v[cctr] = left[lctr];
                lctr++;
                cctr++;
            }
            else
            {
                v[cctr] = right[rctr];
                rctr++;
                cctr++;
            }
        }
        else if (lctr >= left.size())
        {
            v[cctr] = right[rctr];
            rctr++;
            cctr++;
        }
        else
        {
            v[cctr] = left[lctr];
            lctr++;
            cctr++;
        }
    }
}