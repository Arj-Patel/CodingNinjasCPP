#include <iostream>
#include <string>
using namespace std;

void printSubstring(int n, string output)
{
    if (n == 0)
    {
        cout << output << endl;
        return;
    }

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

    for (int i = 0; i < subStr.length(); i++)
    {
        printSubstring(n / 10, subStr.substr(i, 1) + output);
    }
}

void printKeypad(int num)
{

    printSubstring(num, "");
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
