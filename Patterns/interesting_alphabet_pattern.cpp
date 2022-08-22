#include<iostream>
using namespace std; 

int main(){

    int n;
    cin>>n;

    int i = 1;
    int ch = 65 + n - 1;

    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout<<char(ch);
            ch++;
            j++;
        }
        ch = ch - i - 1;
        cout<<endl;
        i++;
    }
    

    return 0;
}