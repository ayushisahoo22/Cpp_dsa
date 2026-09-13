#include<bits/stdc++.h>
using namespace std;

//memoization
// int solve(int i,vector<int>h,vector<int>&dp){
//     if(i==0) return 0;
//     if(dp[i]!=-1) return dp[i];
//     int first=solve(i-1,h,dp)+abs(h[i]-h[i-1]);
//     int second=INT_MAX;
//     if(i>=2){
//         second=solve(i-2,h,dp)+abs(h[i]-h[i-2]);
//     }
//     return dp[i]=min(first,second);
// }

//tabulation
int solve(vector<int>h,vector<int>&dp){
    dp[0]=0;
    int n=h.size();
    for(int i=1;i<n;i++){
        int first=dp[i-1]+abs(h[i]-h[i-1]);
        int second=INT_MAX;
        if(i>1){
            second=dp[i-2]+abs(h[i]-h[i-2]);
        }
        dp[i]=min(first,second);
    }
    return dp[n-1];
}

int frogJump(vector<int>h){
    int n=h.size();
    vector<int>dp(n+1,-1);
    int ans=solve(h,dp);
    return ans;
}

int main(){
    vector<int> height{30, 10, 60, 10, 60, 50};
    cout <<frogJump(height) << endl;
    return 0;
}