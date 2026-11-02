#include<bits/stdc++.h>
using namespace std;

int solve(int i,int target,vector<int>arr,vector<vector<int>>&dp){
    if(target==0) return 1;
    if(i==0) return target==arr[0];
    if(dp[i][target]!=-1) return dp[i][target];
    int notTake=solve(i-1,target,arr,dp);
    int take=0;
    if(arr[i]<=target){
        take=solve(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=take+notTake;
}

int countSumK(vector<int>arr,int k){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
}

int main(){
    int n,k;
    cin >> n>>k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans=countSumK(arr,k);
    cout<<ans;
}