#include <iostream>
using namespace std;

void reverseStringWordWise(char str[])
{
    int i = 0, n = 0;
    while (str[i] != '\0')
    {
        n++;
        i++;
    }

    int start = 0, count = 0;

    int j = n - 1;
    for (int u = 0; u < (n + 1) / 2; u++)
    {
        int temp = str[u];
        str[u] = str[j];
        str[j] = temp;
        j--;
    }

    i = 0;

    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            count++;
        }

        if (str[i] == ' ')
        {
            int end = start + count - 1;
            for (int k = 0; k < ((count + 1) / 2); k++)
            {

                char temp = str[end];
                str[end] = str[start];
                str[start] = temp;
                start++;
                end--;
            }
            start = i + 1;
            count = 0;
        }
        i++;
    }

    int end = n - 1;
    count = end - start + 1;

    for (int k = 0; k < ((count + 1) / 2); k++)
    {

        char temp = str[end];
        str[end] = str[start];
        str[start] = temp;
        start++;
        end--;
    }
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
