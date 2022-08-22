#include <iostream>
using namespace std;

void replaceCharacter(char str[], char c1, char c2)
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

    if (str[0] == c1)
    {
        str[0] = c2;
    }

    replaceCharacter(str + 1, c1, c2);
}

int main()
{
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}
