#include <iostream>
using namespace std;

void sumOfTwoArrays(int *arr1, int n1, int *arr2, int n2, int *output)
{
    int i = n1 - 1, j = n2 - 1, carry = 0, current, outIndex = max(n1, n2);

    while (i >= 0 && j >= 0)
    {
        current = arr1[i] + arr2[j] + carry;
        int temp = current % 10;
        output[outIndex] = temp;
        if (current > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        i--;
        j--;
        outIndex--;
    }

    while (i >= 0)
    {
        current = arr1[i] + carry;
        int temp = current % 10;
        output[outIndex] = temp;
        if (current > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        i--;
        outIndex--;
    }

    while (j >= 0)
    {
        current = arr2[j] + carry;
        int temp = current % 10;
        output[outIndex] = temp;
        if (current > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        j--;
        outIndex--;
    }
    output[0] = carry;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size1;
        cin >> size1;

        int *input1 = new int[size1];

        for (int i = 0; i < size1; ++i)
        {
            cin >> input1[i];
        }

        int size2;
        cin >> size2;

        int *input2 = new int[size2];

        for (int i = 0; i < size2; ++i)
        {
            cin >> input2[i];
        }

        int outsize = 1 + max(size1, size2);

        int *output = new int[outsize];

        sumOfTwoArrays(input1, size1, input2, size2, output);

        for (int i = 0; i < outsize; ++i)
        {
            cout << output[i] << " ";
        }

        delete[] input1;
        delete[] input2;
        delete[] output;
        cout << endl;
    }

    return 0;
}