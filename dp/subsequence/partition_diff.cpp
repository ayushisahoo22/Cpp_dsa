#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mod = 1000000007;
    int solve(
        int index,
        int target,
        vector<int>& arr,
        vector<vector<int>>& dp
    ) {
        if (index == 0 && target == 0 && arr[0] == 0) {
            return 2;
        }
        if (index == 0 && (target == 0 || target == arr[0])) {
            return 1;
        }
        if (index == 0) {
            return 0;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        int notTake = solve(index - 1, target, arr, dp);
        int take = 0;
        if (arr[index] <= target) {
            take = solve(
                index - 1, target - arr[index], arr, dp
            );
        }
        dp[index][target] = (notTake + take) % mod;
        return dp[index][target];
    }

public:
    int countPartitions(vector<int>& arr, int difference) {
        int n = arr.size();
        int totalSum = 0;
        for (int value : arr) {
            totalSum += value;
        }

        int remaining = totalSum - difference;
        if (remaining < 0 || remaining % 2 != 0) {
            return 0;
        }
        int target = remaining / 2;
        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1)
        );
        return solve(n - 1, target, arr, dp);
    }
};


int main() {
    vector<int> arr = {0, 0, 1};
    int difference = 1;
    Solution obj;
    cout << obj.countPartitions(arr, difference);
    return 0;
}