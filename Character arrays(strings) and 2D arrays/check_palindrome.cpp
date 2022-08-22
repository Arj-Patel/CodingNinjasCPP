#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[])
{
    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}