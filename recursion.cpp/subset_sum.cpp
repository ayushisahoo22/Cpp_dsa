#include<bits/stdc++.h>
using namespace std;

//Given an array print all the sum of the subset generated from it, in the increasing order.

void findSubset(int i,vector<int>&arr,int s,vector<int>&res){
    if(i==arr.size()){
        res.push_back(s);
        return;
    }
    findSubset(i+1,arr,s+arr[i],res);
    findSubset(i+1,arr,s,res);
}

vector<int>subset(vector<int>&arr,int n){
    vector<int>res;
    int sum=0;
    findSubset(0,arr,sum,res);
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int>res=subset(arr,n);
    for(auto it:res){
        cout<<it<<" ";
    }
}