#include <iostream>
using namespace std;

void printSubsetsofArray(int arr[], int n, int output[], int n1)
{

    if (n == 0)
    {
        for (int i = 0; i < n1; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    int newOutput[n1 + 1];
    newOutput[0] = arr[0];

    printSubsetsofArray(arr + 1, n - 1, newOutput, n1 + 1);
    printSubsetsofArray(arr + 1, n - 1, output, n1);

    for (int i = 0; i < n1; i++)
    {
        output[n - i] = output[n - i - 1];
    }
    output[0] = newOutput[0];
}

void printSubsetsOfArray(int arr[], int n)
{
    int output[10000];
    printSubsetsofArray(arr, n, output, 0);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
