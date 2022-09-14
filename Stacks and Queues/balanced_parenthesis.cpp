#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.empty() == 1)
            {
                return false;
            }

            if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if (s.empty() == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}