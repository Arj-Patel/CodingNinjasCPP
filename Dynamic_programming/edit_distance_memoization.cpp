#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

/*
int helper(string s1, string s2, int** arr){

//     if(s1.size() == 0){
//         arr[s1.size()][s2.size()] = s2.size();
//         return s2.size();
//     }
//     else if(s2.size() == 0){
//         arr[s1.size()][s2.size()] = s1.size();
//         return s1.size();
//     }

//     if(arr[s1.size()][s2.size()] != -1){
//         return arr[s1.size()][s2.size()];
//     }

//     if(s1[0] == s2[0]){
//         int ans = helper(s1.substr(1), s2.substr(1), arr);
//         arr[s1.size()][s2.size()] == ans;
//         return ans;
//     }
//     else{
//         int a = helper(s1, s1[0]+s2, arr);
//         int b = helper(s1, s2.substr(1), arr);
//         s2[0] = s1[0];
//         int c = helper(s1, s2, arr);
//         arr[s1.size()][s2.size()] == 1+min({a, b, c});
//         return 1+min({a, b, c});
//     }

    if(s1.size() == 0 || s2.size() == 0){
        return max(s1.size(), s2.size());
    }

    if(arr[s1.size()][s2.size()] != -1){
        return arr[s1.size()][s2.size()];
    }

    if(s1[0] == s2[0]){
        int ans = helper(s1.substr(1), s2.substr(1), arr);
        arr[s1.size()][s2.size()] = ans;
        return ans;
    }
    else{
        int a = helper(s1.substr(1), s2, arr);
        int b = helper(s1, s2.substr(1), arr);
        int c = helper(s1.substr(1), s2.substr(1), arr);
        arr[s1.size()][s2.size()] = 1+min({a, b, c});
        return 1+min({a, b, c});
    }

}
*/

int editDistance(string s1, string s2)
{

    int m = s1.size(), n = s2.size();

    int **arr = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        arr[i] = new int[n + 1];
        // for(int j = 0; j <= n; j++){
        //     arr[i][j] = 0;
        // }
    }

    for (int i = 0; i <= n; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        arr[i][0] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = min({arr[i - 1][j - 1], arr[i][j - 1], arr[i - 1][j]}) + 1;
            }
        }
    }

    return arr[m][n];
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}