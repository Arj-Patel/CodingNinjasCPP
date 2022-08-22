#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int counter = i;
        int j = 1;
        while (j <= i)
        {
            cout << counter;
            counter--;
            j++;
        }
        // counter = counter - i + 1;
        i++;
        cout << endl;
    }

    return 0;
}