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
            size[ult_u]+=size[ult_v];
        }
    }
};

bool isValid(int newR,int newC,int n){
    return (newR>=0 && newR<n && newC>=0 && newC<n);
}

int largestIsland(vector<vector<int>>grid){
    int n=grid.size();
    DisjointSet ds(n*n);
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==0) continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjR=row+dr[i];
                int adjC=col+dc[i];
                if(isValid(adjR,adjC,n) && grid[adjR][adjC]){
                    int node=(row*n)+col;
                    int adjNode=(adjR*n)+adjC;
                    if(ds.findPar(node)!=ds.findPar(adjNode)){
                        ds.unionSize(node,adjNode);
                    }
                }
            }
        }
    }
    int maxi=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==1) continue;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            set<int>st;
            for(int i=0;i<4;i++){
                int adjR=row+dr[i];
                int adjC=col+dc[i];
                if(isValid(adjR,adjC,n) && grid[adjR][adjC]){
                    int adjNode=(adjR*n)+adjC;
                    st.insert(ds.findPar(adjNode));
                }
            }
            int t_size=0;
            for(auto it:st){
                t_size+=ds.size[it];
            }
            maxi=max(maxi,t_size+1);
        }
    }
    for(int i=0;i<n*n;i++){
        maxi=max(maxi,ds.size[ds.findPar(i)]);
    }
    return maxi;
}

int main() {
    vector<vector<int>> grid = {
        {1,1},
        {1,1}
    };
    int ans = largestIsland(grid);
    cout << "The size of the largest island is: " << ans;
    return 0;
}