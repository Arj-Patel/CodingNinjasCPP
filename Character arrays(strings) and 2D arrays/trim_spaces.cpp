#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            int j = i;
            while (str[j] != '\0')
            {
                str[j] = str[j + 1];
                j++;
            }
        }
        if (str[i] != ' ')
        {
            i++;
        }
    }
}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}
