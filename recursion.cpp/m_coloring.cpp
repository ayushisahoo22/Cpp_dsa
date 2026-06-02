#include<bits/stdc++.h>
using namespace std;

bool isSafe(int st,int n,int c,bool graph[4][4],int color[]){
    for(int k=0;k<n;k++){
        if(graph[st][k]==1 && color[k]==c){
            return false;
        }
    }
    return true;
}

bool solve(int st,int n,int m,bool graph[4][4],int color[]){
    if(st==n){
        return true;
    }
    for(int i=0;i<m;i++){
        if(isSafe(st,n,i,graph,color)){
            color[st]=i;
            if(solve(st+1,n,m,graph,color)) return true;
            color[st]=0;
        }
    }
    return false;
}

int main(){
    int n=4; //no of nodes
    bool graph[4][4]={
        {0,1,1,1},
        {1,0,1,1},
        {1,1,0,0},
        {1,1,0,0}
    };
    int m=3;   //atmost colors;
    int color[n]={};
    if(solve(0,n,m,graph,color)) cout<<"True";
    else cout<<"False";
}