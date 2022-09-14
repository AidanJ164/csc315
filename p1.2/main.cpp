#include <iostream>
#include <string>
using namespace std;

void find(int start[2], char puzzle[][4], string search, string & word,
          string dir, int row, int col );
void outputWord(string word, int pos[2], string dir);

int main()
{
    char puzzle[4][4] = { { 't', 'h', 'i', 's' },
                          { 'w', 'a', 't', 's' },
                          { 'o', 'a', 'h', 'g' },
                          { 'f', 'g', 'd', 't' } };
    string solutions[13] = { "this", "two", "fat", "fats", "at", "wad", "ad", "hat", "that", "his", "is", "it", "ah"};
    int i, j, k;
    int start[2];
    string word = "";
    
    for (k = 0; k < 13; k++)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                start[0] = i;
                start[1] = j;

                find(start, puzzle, solutions[k], word, "ALL", i, j);
                word.clear();
            }
        }
    }
    return 0;
}

void find(int start[2], char puzzle[4][4], string search, string & word, string dir,
          int row, int col )
{
    if (row < 0 || col < 0 || row >= 4 || col >= 4)
    {
        return;
    }
    
    word += puzzle[row][col];

    if (word == search)
    {
        outputWord(word, start, dir);
        word.pop_back();
        return;
    }
    else if (search.find(word) != string::npos)
    {
        if (dir == "UP" || dir == "ALL")
            find(start, puzzle, search, word, "UP", row - 1, col);
        if (dir == "UPRIGHT" || dir == "ALL")
            find(start, puzzle, search, word, "UPRIGHT", row - 1, col + 1);
        if (dir == "RIGHT" || dir == "ALL")
            find(start, puzzle, search, word, "RIGHT", row, col + 1);
        if (dir == "DOWNRIGHT" || dir == "ALL")
            find(start, puzzle, search, word, "DOWNRIGHT", row + 1, col + 1);
        if (dir == "DOWN" || dir == "ALL")
            find(start, puzzle, search, word, "DOWN", row + 1, col);
        if (dir == "DOWNLEFT" || dir == "ALL")
            find(start, puzzle, search, word, "DOWNLEFT", row + 1, col - 1);
        if (dir == "LEFT" || dir == "ALL")
            find(start, puzzle, search, word, "LEFT", row, col - 1);
        if (dir == "UPLEFT" || dir == "ALL")
            find(start, puzzle, search, word, "UPLEFT", row - 1, col - 1);
    }
 
    word.pop_back();
    return;
}

void outputWord(string word, int pos[2], string dir)
{
    cout << word << " found at (" << pos[0] + 1 << "," << pos[1] + 1 << ") going "
        << dir << endl;
}
