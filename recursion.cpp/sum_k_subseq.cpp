#include<bits/stdc++.h>
using namespace std;

//printing all the subsequence of sum k

void helper(int i,int k,int sum,vector<int>&arr,vector<int>&curr,vector<vector<int>>&res){
    if(i==arr.size()){
        if(sum==k){
            res.push_back(curr);
        }
        return;
    }
    curr.push_back(arr[i]);
    sum+=arr[i];
    helper(i+1,k,sum,arr,curr,res);
    curr.pop_back();
    sum-=arr[i];
    helper(i+1,k,sum,arr,curr,res);
}

vector<vector<int>> cntSub(int k,vector<int>arr){
    vector<vector<int>>res;
    vector<int>curr;
    helper(0,k,0,arr,curr,res);
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
    vector<vector<int>>res=cntSub(k,arr);
    for(auto it:res){
        for(auto n:it){
            cout<<n<<" ";
        }
        cout<<endl;
    }

}