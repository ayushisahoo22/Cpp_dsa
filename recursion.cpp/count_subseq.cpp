#include<bits/stdc++.h>
using namespace std;

int countSubsequence(int i,int k,int sum,vector<int>arr){
    if(i==arr.size()){
        if(sum==k) return 1;
        return 0;
    }
    sum+=arr[i];
    int l=countSubsequence(i+1,k,sum,arr);
    sum-=arr[i];
    int r=countSubsequence(i+1,k,sum,arr);
    return l+r;
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
    int res=countSubsequence(0,k,0,arr);
    cout<<res;
}