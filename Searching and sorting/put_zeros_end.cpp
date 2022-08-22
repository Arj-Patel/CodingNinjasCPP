#include <iostream>
using namespace std;

void pushZeroesEnd(int *arr, int n)
{
    
    /*
    
    ********TLE**********
    //uses for loop in for loop. Can be done without it
    
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != 0)
        {
            continue;
        }
        
        for (int j = i; j < n-1; j++)
        {
            arr[j] = arr[j+1];
        }
               
    }
    
    */
    
    int k = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[k] !=0){
            k++;
        }        
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}