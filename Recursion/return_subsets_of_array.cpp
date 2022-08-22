#include <iostream>
using namespace std;

using namespace std;
int subset(int arr[], int n, int output[][20])
{

    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int ans = subset(arr + 1, n - 1, output);

    int **tempArr = new int *[ans];

    for (int i = 0; i < ans; i++)
    {
        tempArr[i] = new int[20];
    }

    for (int i = 0; i < ans; i++)
    {
        tempArr[i][0] = output[i][0] + 1;
        tempArr[i][1] = arr[0];
        for (int j = 2; j < output[i][0] + 2; j++)
        {
            tempArr[i][j] = output[i][j - 1];
        }
    }

    for (int i = ans; i < 2 * ans; i++)
    {
        for (int j = 0; j < tempArr[i - ans][0] + 1; j++)
        {
            output[i][j] = tempArr[i - ans][j];
        }
    }

    for (int i = 0; i < ans; i++)
    {
        delete[] tempArr[i];
    }
    delete[] tempArr;
    return 2 * ans;
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
