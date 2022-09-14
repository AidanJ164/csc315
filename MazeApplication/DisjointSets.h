#pragma once

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet
{
public:
    DisjointSet();
    DisjointSet(int x);

    void Union(int x, int y);
    int find(int x);
    int parent(int x);
    void setWall(int x, int y);
    bool isWall(int x, int y);

private:
    vector<int> table;
    vector<bool> walls;

    void initialize();
};

inline DisjointSet::DisjointSet()
{
    table.resize(100);
    table.resize(200);
    initialize();
}

inline DisjointSet::DisjointSet(int x)
{
    if (x < 0)
        x = 100;

    table.resize(x);
    walls.resize(x * 2);
    initialize();
}

void DisjointSet::Union(int x, int y)
{
    int pary;
    int parx;

    parx = find(x);
    pary = find(y);

    table.at(y) = x;
    table.at(pary) = parx;
}

inline int DisjointSet::find(int x)
{
    if (table.at(x) < 0)
    {
        return x;
    }
    return find(table.at(x));
}

inline int DisjointSet::parent(int x)
{
    return table.at(x);
}

inline void DisjointSet::initialize()
{
    for (int i = 0; i < table.size(); i++)
        table.at(i) = -1;
    for (int i = 0; i < walls.size(); i++)
        walls.at(i) = true;
}

inline void DisjointSet::setWall(int x, int y)
{
    walls[x + y] = false;
}

inline bool DisjointSet::isWall(int x, int y)
{
    return walls[x + y];
}
