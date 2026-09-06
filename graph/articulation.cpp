#include<bits/stdc++.h>
using namespace std;
int timer=0;
void dfs(int i,int parent,vector<int>adj[],vector<int>&vis,int time[],int low[],vector<int>&mark){
    vis[i]=1;
    time[i]=low[i]=timer++;
    int child=0;
    for(auto it:adj[i]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it,i,adj,vis,time,low,mark);
            low[i]=min(low[i],low[it]);
            if(low[it]>=time[i] && parent!=-1) mark[i]=1;
            child++;
        }else{
            low[i]=min(low[i],time[it]);
        }
    }
    if(parent==-1 && child>1) mark[i]=1;
}

vector<int>articulationPoints(int n,vector<int>adj[]){
    vector<int>vis(n,0),mark(n,0);
    int time[n],low[n];
    for(int i=0;i<n;i++){
        dfs(i,-1,adj,vis,time,low,mark);
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(mark[i]==1){
            ans.push_back(i);
        }
    }
    if(ans.size()==0) return {-1};
    return ans;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}
    };
    vector<int> adj[n];
    for (auto e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> res = articulationPoints(n, adj);
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}