#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionSize(int u,int v){
        int ult_u=findPar(u);
        int ult_v=findPar(v);
        if(ult_u==ult_v) return;
        if(size[ult_u]<=size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }else{
            parent[ult_v]=ult_u;
            size[ult_u]=size[ult_v];
        }
    }
};

int makeConnected(int n,vector<vector<int>>connections){
    if(connections.size()<n-1) return -1;
    int extraEdge=0;
    DisjointSet dsu(n);
    for(auto it:connections){
        int u=it[0];
        int v=it[1];
        if(dsu.findPar(u)==dsu.findPar(v)){
            extraEdge++;
        }else{
            dsu.unionSize(u,v);
        }
    }
    int comp=0;
    for(int i=0;i<n;i++){
        if(dsu.parent[i]==i){
            comp++;
        }
    }
    int ans=comp-1;
    if(extraEdge>=ans) return ans;
    return -1;
}

int main(){
    int n=4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    cout <<makeConnected(n,connections) <<endl;
    return 0;
}