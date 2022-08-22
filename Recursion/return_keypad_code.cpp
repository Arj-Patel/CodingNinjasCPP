#include <iostream>
#include <string>
using namespace std;

int keypad(int n, string output[])
{

    if (n == 0)
    {
        output[0] = "";
        return 1;
    }

    int count = keypad(n / 10, output);

    int currentN = n % 10;

    string subStr;
    if (currentN == 2)
    {
        subStr = "abc";
    }
    else if (currentN == 3)
    {
        subStr = "def";
    }
    else if (currentN == 4)
    {
        subStr = "ghi";
    }
    else if (currentN == 5)
    {
        subStr = "jkl";
    }
    else if (currentN == 6)
    {
        subStr = "mno";
    }
    else if (currentN == 7)
    {
        subStr = "pqrs";
    }
    else if (currentN == 8)
    {
        subStr = "tuv";
    }
    else if (currentN == 9)
    {
        subStr = "wxyz";
    }

    string *tempStr = new string[4 * count];

    int k = 0;

    for (int i = 0; i < subStr.length(); i++)
    {
        for (int j = 0; j < count; j++)
        {
            tempStr[k++] = output[j];
        }
    }

    int l = 0;

    for (int i = 0; i < subStr.length(); i++)
    {
        for (int j = 0; j < count; j++)
        {
            tempStr[l] = tempStr[l] + subStr.substr(i, 1);
            l++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        output[i] = tempStr[i];
    }

    delete[] tempStr;

    return k;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
