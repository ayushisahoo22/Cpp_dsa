#include<bits/stdc++.h>
using namespace std;

int findMinSteps(vector<int>&arr,int st,int e){
    queue<pair<int,int>>q;
    q.push({0,st});
    vector<int>dist(100000,INT_MAX);
    dist[st]=0;
    int mod = 100000;
    while(!q.empty()){
        int d=q.front().first;
        int node=q.front().second;
        q.pop();
        for(auto it:arr){
            int num=(it*node)%mod;
            if(dist[num]>d+1){
                dist[num]=d+1;
                if(num==e) return dist[num];
                q.push({d+1,num});
            }
        }
    }
    return -1;
}

int main(){
    int start = 3, end = 30;
    vector<int> arr = {2, 5, 7};
    int steps=findMinSteps(arr,start,end);
    cout<<steps;
    return 0;
}