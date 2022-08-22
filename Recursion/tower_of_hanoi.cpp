#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxillary, char destination)
{

    if (n == 0)
    {
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxillary);
    cout << source << " " << destination << endl;
    towerOfHanoi(n - 1, auxillary, source, destination);
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}