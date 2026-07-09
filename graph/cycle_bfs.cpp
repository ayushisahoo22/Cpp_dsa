#include<bits/stdc++.h>
using namespace std;

bool detect(int src,vector<int>adj[],vector<int>&visited){
    visited[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});  //no parent of source
    while(!q.empty()){
        int node=q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(visited[it]!=1){
                visited[it]=1;
                q.push({it,node});
            }else if(it != parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v,vector<int>adj[]){
    vector<int>visited(v,0);
    for(int i=0;i<v;i++){
        if(visited[i]!=1){
            bool ans=detect(i,adj,visited);
            if(ans) return true;
        }
    }
    return false;
}

int main(){
    int V = 7;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 4};
    adj[2] = {0, 3};
    adj[3] = {2};
    adj[4] = {1,6};
    adj[5] = {2,6};
    adj[6] = {4,5};
    vector<int> visited(V, 0);
    bool ans=isCycle(V,adj);
    cout<<ans;
}