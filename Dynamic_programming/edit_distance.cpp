#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2)
{

    if (s1.size() == 0 || s2.size() == 0)
    {
        return max(s1.size(), s2.size());
    }

    if (s1[0] == s2[0])
    {
        int ans = editDistance(s1.substr(1), s2.substr(1));
        return ans;
    }
    else
    {
        int a = editDistance(s1.substr(1), s2);
        int b = editDistance(s1, s2.substr(1));
        int c = editDistance(s1.substr(1), s2.substr(1));
        return 1 + min({a, b, c});
    }
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}