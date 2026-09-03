#include<bits/stdc++.h>
using namespace std;

bool isValid(int r,int c,int n){
        return (r>=0 && r<n && c<n && c>=0);
    }

int swimInWater(vector<vector<int>>& grid) {
    int n=grid.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<vector<int>>visited(n,vector<int>(n,0));
    pq.push({grid[0][0],{0,0}});
    visited[0][0]=1;
    int dr[]={0,-1,0,1};
    int dc[]={1,0,-1,0};
    while(!pq.empty()){
        auto it=pq.top();
        int row=it.second.first;
        int col=it.second.second;
        int el=it.first;
        pq.pop();
        if(row==n-1 && col==n-1) return el;
        for(int i=0;i<4;i++){
            int newR=row+dr[i];
            int newC=col+dc[i];
            if(isValid(newR,newC,n) && !visited[newR][newC]){
                visited[newR][newC]=1;
                pq.push({max(el,grid[newR][newC]),{newR,newC}});
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };
    cout << swimInWater(grid) << endl;
    return 0;
}