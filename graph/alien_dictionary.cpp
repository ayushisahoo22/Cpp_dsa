#include<bits/stdc++.h>
using namespace std;

void dfs(int i,stack<int>&st,vector<int>&visited,vector<int>adj[]){
    visited[i]=1;
    for(auto it:adj[i]){
        if(!visited[it]){
            dfs(it,st,visited,adj);
        }
    }
    st.push(i);
}

vector<int>topoSort(int n,vector<int>adj[]){
    stack<int>st;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,st,visited,adj);
        }
    }
    vector<int>res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

string findOrder(string dict[],int n,int k){
    vector<int>adj[k];
    for(int i=0;i<n-1;i++){
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<int> topo=topoSort(k, adj);
    string ans = "";
    for (auto node : topo) {
        ans += char(node + 'a');
    }
    return ans;
}

int main(){
    int N = 5, K = 4;
    string dict[]={"baa", "abcd", "abca", "cab", "cad"};
    string ans = findOrder(dict, N, K);
    for (auto ch:ans){
        cout << ch << " ";
    }
    cout<< endl;
    return 0;
}