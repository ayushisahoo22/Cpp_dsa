#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++){
        if(i<2) dp[i]=cost[i];
        else dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
    }
    return min(dp[n-1],dp[n-2]);
}

int main(){
    vector<int>arr={1,100,1,1,1,100,1,1,100,1};
    int ans=minCostClimbingStairs(arr);
    cout<<ans;
}