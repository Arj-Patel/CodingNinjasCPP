#include <iostream>
#include <cstring>
using namespace std;

void replaceCharacter(char str[], char c1, char c2)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c1)
        {
            str[i] = c2;
        }
        i++;
    }
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