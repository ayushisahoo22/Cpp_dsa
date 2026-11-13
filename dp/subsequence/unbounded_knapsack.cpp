
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    for(int j = 0; j <= W; j++) {
        if(j % wt[0] == 0) {
            dp[0][j] = (j / wt[0]) * val[0];
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= W; j++) {
            int notTake = dp[i-1][j];
            int take = 0;
            if(wt[i] <= j) {
                take = val[i] + dp[i][j-wt[i]];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][W];
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << unboundedKnapsack(wt, val, n, W) << endl;
    return 0;
}
