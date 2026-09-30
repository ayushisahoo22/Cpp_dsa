#include<bits/stdc++.h>
using namespace std;

int solve(int day, int canBuy, vector<int>& prices,vector<vector<long long>>& dp) {
    int n = prices.size();
    if (day == n) {
        return 0;
    }
    if (dp[day][canBuy] != -1) {
        return dp[day][canBuy];
    }

    int bestProfit;
    if (canBuy == 1) {
        int buy = -prices[day]+ solve(day + 1, 0, prices, dp);
        int skip = solve(day + 1, 1, prices, dp);
        bestProfit = max(buy, skip);
    } else {
        int sell = prices[day]+ solve(day + 1, 1, prices, dp);
        int hold = solve(day + 1, 0, prices, dp);
        bestProfit = max(sell, hold);
    }
    dp[day][canBuy] = bestProfit;
    return dp[day][canBuy];
}

int maxProfit(vector<int>arr,int n){
    vector<vector<long long>> dp(
            n, vector<long long>(2, -1));
    return solve(0, 1, arr, dp);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=maxProfit(arr,n);
    cout<<ans;
}