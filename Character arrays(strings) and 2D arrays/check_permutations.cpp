#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char arr1[], char arr2[])
{

    int i = 0, n1 = 0, n2 = 0;

    while (arr1[i] != '\0')
    {
        n1++;
        i++;
    }

    i = 0;

    while (arr2[i] != '\0')
    {
        n2++;
        i++;
    }

    cout << n1 << " " << n2 << endl;

    bool isPresent = 0;

    for (i = 0; i < n1; i++)
    {
        bool isPresent = 0;
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                isPresent = 1;
                arr2[j] = '\0';
                break;
            }
        }
        if (!isPresent)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}