#include<bits/stdc++.h>
using namespace std;

void bfs(int l,vector<int>adj[],vector<int>&v,vector<int>&res){
    queue<int>q;
    q.push(l);
    v[l]=1;
    while(!q.empty()){
        int val=q.front();
        q.pop();
        res.push_back(val);
        for(auto it:adj[val]){
            if(v[it]==0){
                q.push(it);
                v[it]=1;
            }
        }
    }
}

int main() {
    // Number of vertices
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};
    vector<int> visited(V, 0);
    vector<int> result;
    bfs(0, adj, visited, result);
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}