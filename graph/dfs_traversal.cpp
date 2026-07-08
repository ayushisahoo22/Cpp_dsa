#include<bits/stdc++.h>
using namespace std;

void dfs(int l,vector<int>adj[],vector<int>&v,vector<int>&res){
    stack<int>st;
    st.push(l);
    v[l]=1;
    while(!st.empty()){
        int val=st.top();
        st.pop();
        res.push_back(val);
        for(auto it:adj[val]){
            if(v[it]==0){
                st.push(it);
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
    dfs(0, adj, visited, result);
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}