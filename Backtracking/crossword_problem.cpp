#include <bits/stdc++.h>
using namespace std;

void print(char arr[][10])
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return;
}

bool isPossibleRight(char arr[][10], string str, int row, int col)
{

    int j;
    for (j = col; j < str.size() + col; j++)
    {
        if ((arr[row][j] != '-' && arr[row][j] != str[j - col]) || j > 9)
        {
            return false;
        }
    }
    if (j <= 9)
    {
        if (arr[row][j] == '-')
        {
            return false;
        }
    }

    return true;
}

bool isPossibleDown(char arr[][10], string str, int row, int col)
{

    int i;
    for (i = row; i < str.size() + row; i++)
    {
        if ((arr[i][col] != '-' && arr[i][col] != str[i - row]) || i > 9)
        {

            return false;
        }
    }
    if (i <= 9)
    {
        if (arr[i][col] == '-')
        {
            return false;
        }
    }

    return true;
}

void insertRight(bool helper[], char arr[][10], int row, int col, string str)
{

    for (int j = col; j < str.size() + col; j++)
    {
        if (arr[row][j] == '-')
        {
            helper[j - col] = true;
        }
        arr[row][j] = str[j - col];
    }
}

void insertDown(bool helper[], char arr[][10], int row, int col, string str)
{

    for (int i = row; i < str.size() + row; i++)
    {
        if (arr[i][col] == '-')
        {
            helper[i - row] = true;
        }
        arr[i][col] = str[i - row];
    }
}

void removeRight(bool helper[], char arr[][10], int row, int col, string str)
{

    for (int j = col; j < str.size() + col; j++)
    {
        if (helper[j - col] == 1)
        {
            arr[row][j] = '-';
        }
    }
}

void removeDown(bool helper[], char arr[][10], int row, int col, string str)
{

    for (int i = row; i < str.size() + row; i++)
    {
        if (helper[i - row] == 1)
        {
            arr[i][col] = '-';
        }
    }
}

bool crossword(char arr[][10], vector<string> v, int index)
{

    if (index == v.size())
    {
        print(arr);
        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == '-' || arr[i][j] == v[index][0])
            {
                if (isPossibleRight(arr, v[index], i, j))
                {
                    bool helper[v[index].size()] = {0};
                    insertRight(helper, arr, i, j, v[index]);
                    bool ans = crossword(arr, v, index + 1);
                    if (ans)
                    {
                        return true;
                    }
                    else
                    {
                        removeRight(helper, arr, i, j, v[index]);
                    }
                }
                if (isPossibleDown(arr, v[index], i, j))
                {
                    bool helper[v[index].size()] = {0};
                    insertDown(helper, arr, i, j, v[index]);
                    bool ans = crossword(arr, v, index + 1);
                    if (ans)
                    {
                        return true;
                    }
                    else
                    {
                        removeDown(helper, arr, i, j, v[index]);
                    }
                }
            }
        }
    }
    return false;
}

int main()
{

    vector<string> v;
    char arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }

    char ch;
    string str = "";
    while (cin >> ch)
    {
        if (ch != ';')
        {
            str = str + ch;
        }
        else
        {
            v.push_back(str);
            str = "";
        }
    }
    v.push_back(str);

    crossword(arr, v, 0);

    return 0;
}