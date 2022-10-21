#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n)
{

    if (n == 1)
    {
        return 0;
    }

    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;

    if (n % 2 == 0)
    {
        ans1 = countMinStepsToOne(n / 2);
    }

    if (n % 3 == 0)
    {
        ans2 = countMinStepsToOne(n / 3);
    }

    ans3 = countMinStepsToOne(n - 1);

    return min({ans1, ans2, ans3}) + 1;
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}