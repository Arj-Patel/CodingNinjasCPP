#include <iostream>
#include <string>
using namespace std;

void helper(string input, string output)
{

    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < input.length(); i++)
    {
        char firstChar = input[i];
        helper(input.substr(0, i) + input.substr(i + 1), firstChar + output);
    }
}

void printPermutations(string input)
{
    helper(input, "");
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}