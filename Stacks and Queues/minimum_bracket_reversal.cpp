#include <iostream>
#include <string>
using namespace std;

#include <stack>
int countBracketReversals(string input)
{
    if (input.length() == 0 || input.length() == 1)
    {
        return -1;
    }

    stack<char> s;
    int i = 0;
    int count = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '}')
        {
            if (s.empty() == 1)
            {
                s.push('{');
                count++;
            }
            else
            {
                s.pop();
            }
        }
        else
        {
            s.push(input[i]);
        }
        i++;
    }
    int count1 = 0;
    while (s.empty() != 1)
    {
        count1++;
        s.pop();
    }

    if (count1 % 2 == 1)
    {
        return -1;
    }
    else
    {
        return count + (count1 / 2);
    }
}

int main()
{
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}