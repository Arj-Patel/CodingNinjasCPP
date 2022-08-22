#include <iostream>
using namespace std;

void rotate(int *arr, int d, int n)
{
    /*

    ****TLE****

    for (int i = 0; i < d; i++)
    {
        int temp = arr[0];
        int j;
        for (j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[j] = temp;
    }

    */

    /*

    ****Works but extra space****

    int *arr1 = new int[n];

    int j = 0;
    for(int i = d; i < n; i++){
        arr1[j] = arr[i];
        j++;
    }

    for(int i = 0; i < d; i++){
        arr1[j] = arr[i];
        j++;
    }

    for(int i = 0; i < n; i++){
        arr[i] = arr1[i];
    }

    */

    int j = d - 1;
    for (int i = 0; i < d / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }

    j = n - 1;
    for (int i = d; i < (n + d) / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }

    j = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
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