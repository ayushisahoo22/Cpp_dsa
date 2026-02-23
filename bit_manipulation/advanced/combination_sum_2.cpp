#include<bits/stdc++.h>
using namespace std;

// Each element can be used only once
// The input array may contain duplicates

void findCombination(int index,int target,vector<int>&arr,vector<int>&curr,vector<vector<int>>&res){
    if(target==0){
        res.push_back(curr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        curr.push_back(arr[i]);
        findCombination(i+1,target-arr[i],arr,curr,res);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>res;
    vector<int>curr;
    sort(candidates.begin(),candidates.end());
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
    vector<vector<int>>res=combinationSum2(arr,target);
    for(auto it:res){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}