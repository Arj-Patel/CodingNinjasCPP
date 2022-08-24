#include <iostream>
using namespace std;

int arrayRotateCheck(int *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }

    for (int i = 1; i < n - 1; i++)
    {

        if (i == n - 2) // If i reaches the end of the elements to be searched, it means that the array is sorted and hasnt been rotated.
        {
            return 0;
        }
        if ((arr[i - 1] > arr[i]) && (arr[i] < arr[i + 1]))
        {
            return i;
        }
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

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << arrayRotateCheck(input, size) << endl;
        delete[] input;
    }

    return 0;
}