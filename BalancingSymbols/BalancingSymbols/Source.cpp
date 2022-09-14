#include <stack>
#include <fstream>
using namespace std;

int main( int argc, char** argv)
{
    ifstream fin;
    stack<char> s;
    char temp;
    char popped;

    if (argc != 2)
    {
        return 1;
    }
    fin.open(argv[1]);
    
    // Look at item
    while (fin >> temp)
    {
        // If item is an opening symbol, push on stack
        if (temp == '{' || temp == '[' || temp == '(')
        {
            s.push(temp);
        }

        // Else if item is a closing symbol and stack is empty, return error
        else if (temp == '}' || temp == ']' || temp == ')')
        {
            if (s.empty())
            {
                return 2;
            }
            popped = s.top();
            s.pop();
        }
        // Else pop the stack
        // If popped symbol does not correspond to opening symbol, return error

    }
    
    // End of file, if stack is not empty, return an error.
    fin.close();

    return 0;
}