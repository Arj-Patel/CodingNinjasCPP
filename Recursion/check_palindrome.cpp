#include <iostream>
using namespace std;

bool checkPalindrome(char str[])
{

    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    if (n == 0 || n == 1)
    {
        return true;
    }

    if (str[0] != str[n - 1])
    {
        return false;
    }

    str[n - 1] = '\0';

    checkPalindrome(str + 1);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
