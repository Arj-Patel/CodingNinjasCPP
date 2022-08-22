#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int i = 0;
    int spaces = n / 2;
    while (i <= (n / 2) + 1)
    {
        int k = 0;
        while (k <= spaces)
        {
            cout << " ";
            k++;
        }
        spaces--;

        int j = 1;
        while (j <= (2 * i) - 1)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }

    i = (n / 2);
    spaces = 1;
    while (i >= 1)
    {
        int k = 1;
        while (k <= spaces)
        {
            cout << " ";
            k++;
        }
        spaces++;

        int j = i * 2 - 1;
        while (j >= 1)
        {
            cout << "*";
            j--;
        }
        cout << endl;
        i--;
    }

    return 0;
}