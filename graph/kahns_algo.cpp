#include<bits/stdc++.h>
using namespace std;

//TOPOLOGICAL SORT (BFS)

vector<int>topoSortBFS(int v,vector<int>adj[],vector<int>&inDegree){
    queue<int>q;
    for(int i=0;i<v;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vector<int>res;
    while(!q.empty()){
        int val=q.front();
        q.pop();
        res.push_back(val);
        for(auto it:adj[val]){
            inDegree[it]--;
            if(inDegree[it]==0){
                q.push(it);
            }
        }
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
    vector<int>inDegree(V);
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            inDegree[it]++;
        }
    }
    vector<int>res=topoSortBFS(V,adj,inDegree);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}