#include <iostream>
#include <string.h>
using namespace std;

void helper(string str, string output)
{

    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }

    int n1 = str[0] - 48;
    char ch1 = 'a' + n1 - 1;
    helper(str.substr(1), output + ch1);

    if (str.length() >= 2)
    {
        int n2 = n1 * 10 + str[1] - 48;
        char ch2 = 'a' + n2 - 1;
        if (n2 >= 10 && n2 <= 26)
        {
            helper(str.substr(2), output + ch2);
        }
    }
}

void printAllPossibleCodes(string input)
{

    string output = "";
    helper(input, output);
    return;
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
