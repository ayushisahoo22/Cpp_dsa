#include<bits/stdc++.h>
using namespace std;

void solve(int n,int i,int j,string r,vector<vector<int>>&arr,vector<vector<int>>&vis,vector<string>&res){
    if(i==n-1 && j==n-1){
        res.push_back(r);
        return;
    }
    //downward
    if(i+1<n && !vis[i+1][j] && arr[i+1][j]==1){
        vis[i+1][j]=1;
        solve(n,i+1,j,r+"d",arr,vis,res);
        vis[i+1][j]=0;
    }
    //left
    if(j-1>=0 && !vis[i][j-1] && arr[i][j-1]==1){
        vis[i][j-1]=1;
        solve(n,i,j-1,r+"l",arr,vis,res);
        vis[i][j-1]=0;
    }
    //right
    if(j+1<n && !vis[i][j+1] && arr[i][j+1]==1){
        vis[i][j+1]=1;
        solve(n,i,j+1,r+"r",arr,vis,res);
        vis[i][j+1]=0;
    }
    //upward
    if(i-1>=0 && !vis[i-1][j] && arr[i-1][j]==1){
        vis[i-1][j]=1;
        solve(n,i-1,j,r+"u",arr,vis,res);
        vis[i-1][j]=0;
    }
}

vector<string> findPath(vector<vector<int>>arr,int n){
    vector<string>res;
    vector<vector<int>>vis(n,vector<int>(n,0));
    if(arr[0][0]==1){
        vis[0][0]=1;
        solve(n,0,0,"",arr,vis,res);
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    vector<string>ans= findPath(arr,n);
    for(auto it:ans){
        cout<<it<<endl;
    }
}