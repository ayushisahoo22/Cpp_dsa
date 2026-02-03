#include<bits/stdc++.h>
using namespace std;

//check if there exist atleast one subsequence whose sum is k

bool checkSubsequence(int i,int k,int sum,vector<int>&arr,vector<int>&curr){
    if(i==arr.size()){
        if(sum==k){
            return true;
        }
        return false;
    }
    curr.push_back(arr[i]);
    sum+=arr[i];
    if(checkSubsequence(i+1,k,sum,arr,curr)){
        return true;
    }
    curr.pop_back();
    sum-=arr[i];
    if(checkSubsequence(i+1,k,sum,arr,curr)){
        return true;
    }
    return false;
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
    vector<int>curr;
    bool res=checkSubsequence(0,k,0,arr,curr);
    cout<<res;
}