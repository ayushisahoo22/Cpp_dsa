#include<bits/stdc++.h>
using namespace std;

bool detect(pair<int,int>p,vector<int>adj[],vector<int>&visited){
    visited[p.first]=1;
    for(auto it:adj[p.first]){
        if(!visited[it]){
            if(detect({it,p.first},adj,visited)==true) return true;
        }else if(it!=p.second){
            return true;
        }
    }
    return false;
}

bool isCycle(int v,vector<int>adj[]){
    vector<int>visited(v,0);
    for(int i=0;i<v;i++){
        if(visited[i]!=1){
            bool ans=detect({i,-1},adj,visited);
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