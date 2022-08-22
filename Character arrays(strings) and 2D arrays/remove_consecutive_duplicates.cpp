#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char arr[])
{

    int nArr = 0;

    while (arr[nArr] != '\0')
    {
        nArr++;
    }

    // cout<<nArr<<endl;
    int n = 1e6;

    char str[n];
    str[0] = arr[0];

    int j = 1;
    for (int i = 1; i < nArr; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            str[j] = arr[i];
            j++;
        }
    }

    // cout<<j<<endl;
    for (int i = 0; i < j; i++)
    {
        arr[i] = str[i];
    }
    arr[j] = '\0';
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}