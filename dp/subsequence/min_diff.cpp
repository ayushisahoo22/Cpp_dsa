#include<bits/stdc++.h>
using namespace std;

int solve(int i,int target,vector<int>arr,vector<vector<int>>&dp){
    if(target==0) return 1;
    if(i==0) return target==arr[0];
    if(dp[i][target]!=-1) return dp[i][target];
    int notTake=solve(i-1,target,arr,dp);
    int take=false;
    if(arr[i]<=target){
        take=solve(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]=take||notTake;
}

int minDiff(vector<int>arr){
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);
    int target=sum/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    dp[0][0]=1;
    int m=INT_MAX;
    for(int i=0;i<=target;i++){
        if(solve(n-1,target,arr,dp)){
            m=min(m,abs(target-(sum-target)));
        }
    }
    return m;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans=minDiff(arr);
    cout<<ans;
}