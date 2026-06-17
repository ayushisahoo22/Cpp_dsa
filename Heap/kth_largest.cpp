#include<bits/stdc++.h>
using namespace std;

int randomIndex(int l,int r){
    int len=r-l+1;
    return (rand()%len)+l;
}

int partitionUpdate(vector<int>&arr,int left,int right,int n,int pivotIndex){
    int val=arr[pivotIndex];
    swap(arr[left],arr[pivotIndex]);
    int i=left+1;
    for(int j=left+1;j<=right;j++){
        if(arr[j]>val){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[left],arr[i-1]);
    return i-1;
}

int kthLargest(vector<int>arr,int n,int k){
    if(k>n) return -1;
    int left=0, right=n-1;
    while(true){
        int pivotIndex=randomIndex(left,right);
        pivotIndex=partitionUpdate(arr,left,right,n,pivotIndex);
        if(pivotIndex==k-1) return arr[pivotIndex];
        else if(pivotIndex>k-1) right=pivotIndex-1;
        else left=pivotIndex+1;
    }
    return -1;
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
    int ans=kthLargest(arr,n,k);
    cout<<ans;
    return 0;
}