#include <iostream>
using namespace std;

int main()
{

    int n1, m1, n2, m2;
    cout << "Enter n1, m1, n2, m2: ";
    cin >> n1 >> m1 >> n2 >> m2;

    if (m1 != n2)
    {
        cout << "These matrices cannot be multiplied." << endl;
        return 0;
    }

    int arr1[100][100];
    int arr2[100][100];
    int ans[100][100];

    cout << "Enter matrix 1" << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter matrix 2" << endl;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            int sum = 0;
            for (int k = 0; k < m1; k++)
            {
                sum += (arr1[i][k] * arr2[k][j]);
            }
            ans[i][j] = sum;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}