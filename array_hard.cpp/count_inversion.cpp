#include<bits/stdc++.h>
using namespace std;

// Given an array of N integers, count the inversion of the array (using merge-sort).
// Inversion of an array: for all i & j < size of array,
// if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

//TC->O(NlogN)

int merge(vector<int> arr,int low,int mid,int high){
    int cnt=0;
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]>arr[right]){
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }else{
            temp.push_back(arr[left]);
            left++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<high;i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}

int mergeSort(vector<int> arr,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=mergeSort(arr,0,n-1);
    cout<<ans;
}