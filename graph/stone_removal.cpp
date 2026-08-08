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

int removeStones(vector<vector<int>>stones){
    int n=stones.size();
    int maxRow=INT_MIN,maxCol=INT_MIN;
    for(int i=0;i<n;i++){
        maxRow=max(maxRow,stones[i][0]);
        maxCol=max(maxCol,stones[i][1]);
    }
    DisjointSet dsu(maxRow+maxCol+1);
    unordered_map<int,int>stoneNodes;
    for(auto it:stones){
        int r=it[0];
        int c=it[1]+maxRow+1;
        dsu.unionSize(r,c);
        stoneNodes[r]=1;
        stoneNodes[c]=1;
    }
    int comp=0;
    for(auto it:stoneNodes){
        if(dsu.findPar(it.first)==it.first) comp++;
    }
    return n-comp;
}

int main() {
    vector<vector<int>>stones = {
        {0, 0},{0, 1},{1, 0},{1, 2},{2, 1},{2, 2}
    };
    cout <<removeStones(stones)<<endl;
    return 0;
}