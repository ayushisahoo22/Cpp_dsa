#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int>&visited,stack<int>&st,vector<int>adj[]){
    visited[i]=1;
    for(auto it:adj[i]){
        if(!visited[it]){
            dfs(it,visited,st,adj);
        }
    }
    st.push(i);
}

vector<int>topoSort(int v,vector<int>adj[]){
    vector<int>visited(v,0);
    vector<int>res;
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,st,adj);
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main(){
    int V = 6, E = 6;
    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    vector<int>res=topoSort(V,adj);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}