#include <iostream>
#include <iomanip>
#include "DisjointSets.h"

using namespace std;
bool isAdjacent(int first, int last, int width);
void printMaze(DisjointSet maze, int width, int height);
void printSet(DisjointSet maze, int size);

int main()
{
    int width;
    int height;
    int size;
    int r1;
    int r2;

    cout << "Enter the maze width: ";
    cin >> width;

    cout << "Enter the maze height: ";
    cin >> height;

    size = height * width;
    DisjointSet maze(size);

    srand(time(0));

    while (maze.find(size-1) != maze.find(0))
    {
        r1 = rand() % size;
        r2 = rand() % size;

        if (isAdjacent(r1, r2, width) && maze.find(r1) != maze.find(r2))
        {
            maze.Union(r1, r2);
            maze.setWall(r1, r2);
        }
    }

    printMaze(maze, width, height);

    return 0;
}

void printSet(DisjointSet maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i << " :: " << maze.parent(i) << " :: " << maze.find(i) << endl;
    }
}

void printMaze(DisjointSet maze, int width, int height)
{
    int index;
    int size = width * height;
    // upper border +-+-+-+-+-+
    // print +- if index is disconnected from index + width
    // left border | | | | | |
    // print |  if index is disconnected from index + 1
    // lower border +-+-+-+-+-+

    for (int i = 0; i < width; i++)
    {
        cout << "+--";
    }
    cout << "+\n";

    for (int i = 0; i < height; i++)
    {
        if (i == 0)
            cout << "   ";
        else
            cout << "|  ";
        for (int j = 0; j < width - 1; j++)
        {
            index = i * width + j;
            if (!maze.isWall(index, index + 1))
            {
                cout << "   ";
            }
            else
                cout << "|  ";
        }
        if (i == height - 1)
            cout << " \n";
        else
            cout << "|\n";

        for (int j = 0; j < width; j++)
        {
            index = i * width + j;
            if (index + width >= size)
            {
                cout << "+--";
            }
            else if (!maze.isWall(index, index + width))
                cout << "+  ";
            else
                cout << "+--";
        }
        cout << "+\n";
    }
}

bool isAdjacent(int first, int last, int width)
{
    if (abs(first - last) == 1 && abs((first % width) - (last % width)) == 1)
    {
        return true;
    }
    if (abs(first - last) == width)
    {
        return true;
    }
    return false;
}