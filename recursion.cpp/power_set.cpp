#include<bits/stdc++.h>
using namespace std;

void helper(int i,vector<int>&arr,vector<int>&curr,vector<vector<int>>&res){
    if(i==arr.size()){
        res.push_back(curr);
        return;
    }
    curr.push_back(arr[i]);
    helper(i+1,arr,curr,res);
    curr.pop_back();
    helper(i+1,arr,curr,res);
}

vector<vector<int>>powerSet(vector<int>&arr){
    vector<vector<int>>res;
    vector<int>curr;
    helper(0,arr,curr,res);
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
    vector<vector<int>>res=powerSet(arr);
    for(auto it:res){
        cout<<"[";
        for(int x:it){
            cout<<x<<" ";
        }
        cout<<"]\n";
    }
}