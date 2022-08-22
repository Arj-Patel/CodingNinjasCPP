#include <iostream>
using namespace std;

void pairStar(char str[])
{

    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    if (n == 1)
    {
        return;
    }

    if (str[0] == str[1])
    {
        for (int i = 0; i < n - 1; i++)
        {
            str[n - i] = str[n - i - 1];
        }
        str[1] = '*';
        str[n + 1] = '\0';
        pairStar(str + 2);
    }
    pairStar(str + 1);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}