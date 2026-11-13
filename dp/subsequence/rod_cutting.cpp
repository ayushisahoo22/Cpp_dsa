#include<bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> price, int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notTake=dp[i-1][j];
                int take=0;
                if(i+1<=j){
                    take=price[i]+dp[i][j-(i+1)];
                }
                dp[i][j]=max(take,notTake);
            }
        }
     return dp[n-1][n];
    }
int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int ans=rodCutting(prices,n);
    cout<<ans;
}