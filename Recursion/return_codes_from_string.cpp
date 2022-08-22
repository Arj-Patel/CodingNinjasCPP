#include <iostream>
#include <cstring>
using namespace std;

int getCodes(string str, string output[10000])
{

    if (str.length() == 0)
    {
        return 1;
    }

    int ans1 = 0;
    char ch1;

    if (str.length() >= 2)
    {
        int n1 = (str[0] - 48) * 10 + str[1] - 48;
        ch1 = 'a' + n1 - 1;

        if (n1 >= 10 && n1 <= 26)
        {
            ans1 = getCodes(str.substr(2), output);
        }
        for (int i = 0; i < ans1; i++)
        {
            output[i] = ch1 + output[i];
        }
    }
    int ans2 = getCodes(str.substr(1), output + ans1);

    int n2 = str[0] - 48;
    char ch2 = 'a' + n2 - 1;

    for (int i = ans1; i < ans1 + ans2; i++)
    {
        output[i] = ch2 + output[i];
    }

    return ans1 + ans2;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
