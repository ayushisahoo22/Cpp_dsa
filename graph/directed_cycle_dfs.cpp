#include<bits/stdc++.h>
using namespace std;

bool dfs(int i,vector<int>&visited,vector<int>&pathVisited,vector<int>adj[]){
    visited[i]=1;
    pathVisited[i]=1;
    for(auto it:adj[i]){
        if(!visited[it] && !pathVisited[it]){
            if(dfs(it,visited,pathVisited,adj)==true) return true;
        }else if(pathVisited[it]){
            return true;
        }
    }
    pathVisited[i]=0;
    return false;
}

bool isCyclic(int nodes,vector<int>adj[]){
    vector<int>visited(nodes,0);
    vector<int>pathVisited(nodes,0);
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            if(dfs(i,visited,pathVisited,adj)==true){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
    bool ans = isCyclic(V, adj);
	if (ans)
		cout << "True\n";
	else
		cout << "False\n";
	return 0;
}