#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(
            n,
            vector<long long>(amount + 1, 0)
        );
        for (int currentAmount = 0;
             currentAmount <= amount;
             currentAmount++) {
            if (currentAmount % coins[0] == 0) {
                dp[0][currentAmount] = 1;
            }
        }
        for (int index = 1; index < n; index++) {
            for (int currentAmount = 0;
                 currentAmount <= amount;
                 currentAmount++) {
                long long notTaken =
                    dp[index - 1][currentAmount];
                long long taken = 0;
                if (coins[index] <= currentAmount) {
                    taken = dp[index][
                        currentAmount - coins[index]
                    ];
                }
                dp[index][currentAmount] =
                    notTaken + taken;
            }
        }
        return dp[n - 1][amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    Solution obj;
    cout << obj.change(amount, coins) << endl;
    return 0;
}