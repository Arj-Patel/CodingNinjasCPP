#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    int smallOutput1 = fibonacci(n - 1);
    int smallOutput2 = fibonacci(n - 2);

    return smallOutput1 + smallOutput2;
}

int main()
{

    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}