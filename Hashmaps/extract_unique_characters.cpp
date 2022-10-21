#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str)
{

    string output = "";
    unordered_map<char, int> unChar;

    for (int i = 0; i < str.size(); i++)
    {
        if (unChar[str[i]] == 0)
        {
            output = output + str[i];
            unChar[str[i]]++;
        }
    }

    return output;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}