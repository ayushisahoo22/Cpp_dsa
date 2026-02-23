#include<bits/stdc++.h>
using namespace std;

// You can use the same element unlimited times
// The input array contains distinct elements (no duplicates)

void findCombination(int i,int target,vector<int>&candidates,vector<int>&curr,vector<vector<int>>&res){
    if(i==candidates.size()){
        if(target==0){
            res.push_back(curr);
        }
        return;
    }
    if(candidates[i]<=target){
        curr.push_back(candidates[i]);
        findCombination(i,target-candidates[i],candidates,curr,res);
        curr.pop_back();
    }
    findCombination(i+1,target,candidates,curr,res);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>res;
    vector<int>curr;
    findCombination(0,target,candidates,curr,res);
    return res;
}

int main(){
    int target,n;
    cout<<"Enter n and target: ";
    cin>>n>>target;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<vector<int>>res=combinationSum(arr,target);
    for(auto it:res){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}