#include<bits/stdc++.h>
using namespace std;

//tabulation

// int minimumTotal(vector<vector<int>>triangle){
//     int n=triangle.size();
//     vector<vector<int>>dp(n,vector<int>(n,0));
//     for(int j=0;j<n;j++){
//         dp[n-1][j]=triangle[n-1][j];
//     }
//     for(int i=n-2;i>=0;i--){
//         for(int j=0;j<=i;j++){
//             int d=dp[i+1][j];
//             int dg=dp[i+1][j+1];
//             dp[i][j]=triangle[i][j]+min(d,dg);
//         }
//     }
//     return dp[0][0];
// }

//space optimization
int minimumTotal(vector<vector<int>>triangle){
    int n=triangle.size();
    vector<int>dp=triangle[n-1];
    for(int i=n-2;i>=0;i--){
        vector<int>temp(i+1,0);
        for(int j=0;j<=i;j++){
            temp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
        }
        dp=temp;
    }
    return dp[0];
}

int main(){
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout <<minimumTotal(triangle);
    return 0;
}