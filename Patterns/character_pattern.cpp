#include<iostream>
using namespace std; 

int main(){

    int n;
    cin>>n;

    int i = 1;
    int ch = 65;

    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout<<char(ch);
            ch++;
            j++;
        }
        cout<<endl;
        ch = ch - i + 1;
        i++;
    }
    

    return 0;
}