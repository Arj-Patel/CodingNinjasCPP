#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    int *temp1 = new int[d];
    int *temp2 = new int[n - d];

    for (int i = 0; i < d; i++)
    {
        temp1[i] = input[i];
    }
    for (int i = d; i < n; i++)
    {
        temp2[i - d] = input[i];
    }
    for (int i = 0; i < n - d; i++)
    {
        input[i] = temp2[i];
    }
    for (int i = n - d; i < n; i++)
    {
        input[i] = temp1[i - n + d];
    }

    delete[] temp1;
    delete[] temp2;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}