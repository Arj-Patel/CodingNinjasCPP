#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *str)
{

    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    if (n == 0)
    {
        return;
    }

    if (str[0] == str[1])
    {
        for (int i = 1; i < n; i++)
        {
            str[i] = str[i + 1];
        }
        removeConsecutiveDuplicates(str);
    }
    else
    {
        removeConsecutiveDuplicates(str + 1);
    }
}
int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}