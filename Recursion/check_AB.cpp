#include <iostream>
using namespace std;

using namespace std;

bool checkab(char str[], int n)
{

    if (n == 1 && str[0] == 'a')
    {
        return true;
    }
    else if (n == 1 && str[0] != 'a')
    {
        return false;
    }

    bool ans = checkab(str, n - 1);

    if (str[n - 1] == 'a')
    {
        if (str[n - 2] == 'a' || (str[n - 2] == 'b' && str[n - 3] == 'b'))
        {
            return ans;
        }
        else
        {
            return false;
        }
    }
    else if (str[n - 1] == 'b')
    {
        if ((str[n - 2] == 'b' && str[n - 3] == 'a') || (str[n - 2] == 'a' && str[n] == 'b'))
        {
            return ans;
        }
        else
        {
            return false;
        }
    }
}

bool checkAB(char str[])
{

    int n = 0;
    while (str[n] != '\0')
    {
        n++;
    }
    return checkab(str, n);
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
