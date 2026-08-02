#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>>& edges) {
    vector<pair<int,int>>adj[V];
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(V,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node]) continue;
        sum+=d;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                pq.push({it.second,it.first});
            }
        }
    }
    return sum;
}

int main(){
    int v=3;
    vector<vector<int>>edges={{0,1,5},{1,2,3},{0,2,1}};
    int min=spanningTree(v,edges);
    cout<<min;
    return 0;
}