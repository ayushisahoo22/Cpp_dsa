#include<bits/stdc++.h>
using namespace std;

// Given an array of integers A and integer k.
// Find the total number of subarrays having bitwise XOR of all elements equal to k.

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;

    unordered_map<int,int>mpp;
    mpp[0]=1;
    int xr=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        xr^=arr[i];
        if(mpp.find(xr^k)!=mpp.end()){
            cnt+=mpp[xr^k];
        }
        mpp[xr]++;
    }
    cout<<cnt;
}