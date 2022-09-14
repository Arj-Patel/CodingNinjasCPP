#include <iostream>
#include <string>
using namespace std;

#include <stack>
bool checkRedundantBrackets(string str)
{

    stack<char> s;
    int i = 0;

    while (str[i] != '\0')
    {

        if (str[i] == '(' || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            bool chkOp = 0;
            while (s.top() != '(')
            {
                chkOp = 1;
                s.pop();
            }

            if (chkOp == 0)
            {
                return true;
            }

            s.pop();
            if (s.empty() == 1)
            {
                return false;
            }

            if (s.top() == '(')
            {
                return true;
            }
        }

        i++;
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}