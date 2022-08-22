#include <iostream>
#include <string>
using namespace std;

int factorial(int length)
{

    if (length == 0 || length == 1)
    {
        return 1;
    }

    return length * factorial(length - 1);
}

int returnPermutations(string input, string output[])
{

    if (input.length() == 0)
    {
        return 1;
    }

    int ans;

    for (int i = 0; i < input.length(); i++)
    {
        ans = returnPermutations(input.substr(0, i) + input.substr(i + 1), output + i * factorial(input.length() - 1));
        for (int j = i * factorial(input.length() - 1); j < i * factorial(input.length() - 1) + ans; j++)
        {
            output[j] = input[i] + output[j];
        }
    }
    return (ans) * (input.length());
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
