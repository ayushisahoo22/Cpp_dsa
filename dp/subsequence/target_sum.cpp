#include <bits/stdc++.h>
using namespace std;

bool helper(int i, vector<int>& arr, int t, int sum,
            vector<vector<int>>& dp){
    if(sum == t)
        return true;
    if(i == arr.size())
        return false;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    bool take = helper(i + 1, arr, t, sum + arr[i], dp);
    bool notTake = helper(i + 1, arr, t, sum, dp);
    return dp[i][sum] = take || notTake;
}

bool isSubsetSum(vector<int> arr, int target){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return helper(0, arr, target, 0, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    if(isSubsetSum(arr, target))
        cout << "true";
    else
        cout << "false";
    return 0;
}