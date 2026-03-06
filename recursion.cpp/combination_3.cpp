#include<bits/stdc++.h>
using namespace std;

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.

void solve(int index,vector<int>&curr,vector<vector<int>>&res,int k,int n){
    if(n==0 && curr.size()==k){
        res.push_back(curr);
        return;
    }
    for(int i=index;i<=9;i++){
        if(i>n) break;
        curr.push_back(i);
        solve(i+1,curr,res,k,n-i);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>curr;
    vector<vector<int>>res;
    solve(1,curr,res,k,n);
    return res;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<vector<int>>ans=combinationSum3(k,n);
    for(auto it:ans){
        for(auto p:it){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}