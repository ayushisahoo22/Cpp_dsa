#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums where every element appears three times except for one,
// which appears exactly once. Find the single element and return it.

int findMissing(vector<int>arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i=i+3){
        if(arr[i]!=arr[i-1]){
            return arr[i-1];
        }
    }
    return arr[n-1];
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
    int ans=findMissing(arr);
    cout<<ans;
}