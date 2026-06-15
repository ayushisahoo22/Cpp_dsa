#include<bits/stdc++.h>
using namespace std;

void heapify(int i,vector<int>&arr,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(largest,arr,n);
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter elements of min heap: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}