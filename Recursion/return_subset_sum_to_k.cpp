#include <iostream>
using namespace std;

using namespace std;
int subsetSumToK(int arr[], int n, int output[][50], int k)
{

    if (k == 0)
    {
        return 1;
    }
    else if (n == 0 || k < 0)
    {
        return 0;
    }

    int subset1 = subsetSumToK(arr + 1, n - 1, output, k);
    int subset2 = subsetSumToK(arr + 1, n - 1, output + subset1, k - arr[0]);

    for (int i = subset1; i < subset1 + subset2; i++)
    {

        for (int j = output[i][0]; j > 0; j--)
        {
            output[i][j + 1] = output[i][j];
        }

        output[i][1] = arr[0];
        output[i][0]++;
    }

    return subset1 + subset2;
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
