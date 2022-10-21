#include<iostream>
using namespace std;

int main(){
	
    int n;
    cin>>n;
    
    int i = 1;
    int spaces = n;
    
    while(i <= n){
        int t = 1;
        while(t < spaces){
            cout<<" ";
            t++;
        }
        spaces--;
        
        int j = 1;
        
        int k = i;
        while(j <= i){
            cout<<k;
            k--;
            j++;
        }
        
        j = 1;
        k = 2;
        while(j < i){
            cout<<k;
            k++;
            j++;
        }
        
        i++;
        cout<<endl;
    }
  

    return 0;
}

