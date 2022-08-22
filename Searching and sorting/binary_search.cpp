#include <iostream>
using namespace std;

int binSearch(int arr[], int n, int num)
{

    int startIndex = 0, endIndex = n - 1;
    

    while (startIndex <= endIndex)
    {
        int midIndex = (startIndex + endIndex) / 2;
        if (arr[midIndex] == num)
        {
            return midIndex;
        }
        else if (arr[midIndex] > num)
        {
            endIndex = midIndex - 1;
        }
        else if (arr[midIndex] < num)
        {
            startIndex = midIndex + 1;
        }
    }
    return -1;
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];

    int num;
    cin >> num;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int numIndex = binSearch(arr, n, num);

    if (numIndex != -1)
    {
        cout << "The index of the required element is: " << numIndex << endl;
    }
    else
    {
        cout << "The number is not present in the array" << endl;
    }

    delete arr;

    return 0;
}