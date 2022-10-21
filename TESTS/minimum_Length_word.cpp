#include <iostream>
using namespace std;

/* input - Input String
 *  output - Save the result in the output array (passed as argument). You don’t have to
 *  print or return the result
 */

void minLengthWord(char str[], char output[])
{

    int start = 0, end, i = 0, currMin, minLength = 2147483647, minS, minE;

    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }

    while (i <= n)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            end = i;
            currMin = end - start;
            if (currMin < minLength)
            {
                minLength = currMin;
                minS = start;
                minE = end;
            }
            start = i + 1;
        }
        i++;
    }

    int j = 0;
    for (i = minS; i < minE; i++)
    {
        output[j] = str[i];
        j++;
    }
    output[j] = '\0';
}

int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
