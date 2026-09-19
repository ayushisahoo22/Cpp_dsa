#include<bits/stdc++.h>
using namespace std;

//memoization

// int solve(int i,int last,vector<vector<int>>points,vector<vector<int>>&dp){
//     if(dp[i][last]!=-1) return dp[i][last];
//     if(i==0){
//         int maxi=0;
//         for(int j=0;j<=2;j++){
//             if(j!=last){
//                 maxi=max(maxi,points[0][j]);
//             }
//         }
//         return dp[i][last]=maxi;
//     }
//     int maxi=0;
//     for(int j=0;j<=2;j++){
//         if(j!=last){
//             int a=points[i][j]+solve(i-1,j,points,dp);
//             maxi=max(maxi,a);
//         }
//     }
//     return dp[i][last]=maxi;
// }

//tabulation
// int ninjaTraining(int n,vector<vector<int>>points){
//     vector<vector<int>>dp(n,vector<int>(4,-1));
//     dp[0][0]=max(points[0][1],points[0][2]);
//     dp[0][1]=max(points[0][0],points[0][2]);
//     dp[0][2]=max(points[0][0],points[0][1]);
//     dp[0][3]=max({points[0][0],points[0][1],points[0][2]});
//     for(int i=1;i<n;i++){
//         for(int last=0;last<4;last++){
//             dp[i][last]=0;
//             for(int task=0;task<=2;task++){
//                 if(task!=last){
//                     int a=points[i][task]+dp[i-1][task];
//                     dp[i][last]=max(dp[i][last],a);
//                 }
//             }
//         }
//     }
//     return dp[n-1][3];
// }

int ninjaTraining(int n,vector<vector<int>>points){
    vector<int>prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max({points[0][0],points[0][1],points[0][2]});
    for(int i=1;i<n;i++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<=2;task++){
                if(task!=last){
                    int a=points[i][task]+prev[task];
                    temp[last]=max(temp[last],a);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
}

int main(){
    vector<vector<int>> points = {{1, 2, 5},
                                   {3, 1, 1},
                                   {3, 3, 3}};

    int n = points.size();
    cout << ninjaTraining(n, points);
}