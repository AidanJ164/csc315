#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void insertionSort(vector<int>& array);
void shellSort(vector<int>& array);

int main()
{
    vector<int> v(20);

    for (int i = 0; i < v.size(); i++)
        v[i] = rand() % 500;
    
    for (int i = 0; i < v.size(); i++)
        cout << setw(4) << v[i] << " ";
    cout << endl;

    shellSort(v);

    for (int i = 0; i < v.size(); i++)
        cout << setw(4) << v[i] << " ";
    return 0;
}

void insertionSort(vector<int>& array)
{
    int i, j;

    for (i = 1; i < array.size(); i++)
    {
        j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            swap(array[j - 1], array[j]);
            j--;
        }
    }
}

void shellSort(vector<int>& a)
{
    int gap, i, j, tmp;
    if ((a.size() / 2) % 2 == 1)
        gap = a.size() / 2;
    else
        gap = (a.size() / 2) - 1;
    for (; gap > 0; gap -= 2)
    {
        for (i = gap; i < a.size(); i++)
        {
            tmp = move(a[i]);
            j = i;

            for (; j >= gap && tmp < a[j - gap]; j -= gap)
                a[j] = move(a[j - gap]);
            a[j] = move(tmp);
        }
        for (int i = 0; i < a.size(); i++)
            cout << setw(4) << a[i] << " ";
        cout << endl;
    }
}