#include <iostream>
using namespace std;

int stringToNumber(char str[])
{
    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    if (n == 0)
    {
        return 0;
    }

    int ans = stringToNumber(str + 1);

    if (str[0] == '0')
    {
        return ans;
    }
    else
    {
        int multiplier = 1;
        int x = n - 1;
        while (x > 0)
        {
            multiplier *= 10;
            x--;
        }

        int charToInt = str[0] - 48;

        return ans + charToInt * multiplier;
    }
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}