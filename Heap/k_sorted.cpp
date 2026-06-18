#include<bits/stdc++.h>
using namespace std;

vector<int>sorted(vector<int>arr,int k){
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for(int i=0;i<=k && i<arr.size();i++){
        minHeap.push(arr[i]);
    }
    vector<int>res;
    for(int i=k+1;i<arr.size();i++){
        res.push_back(minHeap.top());
        minHeap.pop();
        minHeap.push(arr[i]);
    }
    while(!minHeap.empty()){
        res.push_back(minHeap.top());
        minHeap.pop();
    }
    return res;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int>res=sorted(arr,k);
    for(auto it:res){
        cout<<it<<" ";
    }
}