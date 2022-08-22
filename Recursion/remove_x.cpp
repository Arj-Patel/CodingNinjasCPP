#include <iostream>
using namespace std;

void removeX(char str[])
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

    if (str[0] == 'x')
    {
        for (int i = 0; i < n - 1; i++)
        {
            str[i] = str[i + 1];
        }
        str[n - 1] = '\0';
    }

    if (str[0] != 'x')
    {
        removeX(str + 1);
    }
    else
    {
        removeX(str);
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}