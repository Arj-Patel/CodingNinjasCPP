#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string getCompressedString(string &input)
{

    int startindex = 0;
    int currentindex = 0;
    int count = 0;
    string k = "";
    while (startindex < input.length())
    {
        if (input[startindex] == input[currentindex])
        {
            count++;
            currentindex++;
        }
        else
        {
            if (count > 1)
            {
                k = k + input[startindex] + to_string(count);
            }
            else
            {
                k = k + input[startindex];
            }
            count = 0;
            startindex = currentindex;
        }
    }
    return k;
}

int main()
{
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}