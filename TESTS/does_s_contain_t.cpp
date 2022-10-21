#include <iostream>
using namespace std;

bool checksequenece(char large[], char *small)
{

    int ln = 0, sn = 0;
    while (large[ln] != '\0')
    {
        ln++;
    }
    while (small[sn] != '\0')
    {
        sn++;
    }
    if (sn == 0 && ln != 0)
    {
        return true;
    }
    else if (sn != 0 && ln == 0)
    {
        return false;
    }
    else if (ln == 0 && sn == 0)
    {
        return true;
    }

    int lchk = 0;
    while (large[lchk] != '\0')
    {
        if (large[lchk] == small[0])
        {
            break;
        }
        lchk++;
    }
    if (large[lchk] == '\0')
    {
        return false;
    }
    return checksequenece(large + lchk + 1, small + 1);
}

int main()
{
    char large[10000];
    char small[10000];
    cin >> large;
    cin >> small;
    bool x = checksequenece(large, small);

    if (x)
        cout << "true";
    else
        cout << "false";
}
