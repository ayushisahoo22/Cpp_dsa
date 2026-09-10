#include <bits/stdc++.h>
using namespace std;

// Function to calculate Fibonacci using memoization
int fib(int n,vector<int>& dp) {
    // If base case return n
    if(n<=1) return n;

    // If already computed, return stored value
    if (dp[n]!=-1) return dp[n];

    // Otherwise compute and store
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main() {
    int n = 10;
    vector<int>dp(n+1,-1);
    cout<<fib(n,dp);
    return 0;
}