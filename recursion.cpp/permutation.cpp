#include<bits/stdc++.h>
using namespace std;

//generate all the permutation

void find(vector<int>nums,vector<int>&curr,vector<vector<int>>&res,vector<bool>&visited){
    if(curr.size()==nums.size()){
        res.push_back(curr);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i]) continue;
        curr.push_back(nums[i]);
        visited[i]=true;
        find(nums,curr,res,visited);
        visited[i]=false;
        curr.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<int>curr;
    vector<vector<int>>res;
    vector<bool>visited(nums.size(),false);
    find(nums,curr,res,visited);
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
    vector<vector<int>>res=permute(arr);
    for(auto it:res){
        for(auto p:it){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}