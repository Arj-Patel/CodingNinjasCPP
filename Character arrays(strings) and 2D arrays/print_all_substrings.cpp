#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char str[])
{
    int n = strlen(str);

    int t = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = k; i < n; i++)
        {
            for (int j = t; j <= i; j++)
            {
                cout << str[j];
            }
            cout << endl;
        }
        t++;
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}