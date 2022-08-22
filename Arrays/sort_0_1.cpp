#include <iostream>
#include <algorithm>
using namespace std;

void sortZeroesAndOne(int *input, int size)
{

    int i = 0;
    int j = size - 1;

    while (i < j)
    {

        while (true)
        {
            if (input[j] == 1)
            {
                j--;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            if (input[i] == 0)
            {
                i++;
            }
            else{
                break;    
            }
            
        }
        input[i] = 0;
        input[j] = 1;
        
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int size;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        sortZeroesAndOne(input, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        cout << endl;
        delete[] input;
    }

    return 0;
}