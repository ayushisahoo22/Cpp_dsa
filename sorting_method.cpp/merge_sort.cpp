//Merge sort

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include<vector>
void merge(int arr[],int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
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
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(int arr[],int low,int high){
    int mid=(high+low)/2;
    if(low>=high) return;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    int low=0,high=n-1;
    int arr[100];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,low,high);
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}