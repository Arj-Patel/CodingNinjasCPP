#include <iostream>
using namespace std;

void replacePi(char str[])
{
    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    if (n == 1 || n == 0)
    {
        return;
    }

    if (str[0] == 'p' && str[1] == 'i')
    {
        for (int i = 2; i < n; i++)
        {
            str[n - i + 2] = str[n - i + 1];
        }
        str[2] = '4';

        for (int i = 2; i < n + 1; i++)
        {
            str[n + 3 - i] = str[n - i + 2];
        }
        str[2] = '1';
        str[0] = '3';
        str[1] = '.';
    }

    replacePi(str + 1);
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}