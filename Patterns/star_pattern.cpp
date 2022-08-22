#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int i = 1;
    int spaces = n;

    while (i <= n)
    {
        int k = 1;
        while (k < spaces)
        {
            cout<<" ";
            k++;
        }
        spaces--;

        int j = 1;
        while (j <= ((2*i)-1))
        {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}