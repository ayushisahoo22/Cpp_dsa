#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the sum: ";
    cin>>k;
    long long sum=0;int maxSum=0;
    unordered_map<long long,int>mpp;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        //to update maxSum if sum=k
        if(sum==k){
            maxSum=i+1;
        }
        //to check if sum-k is present
        if(mpp.find(sum-k)!=mpp.end()){
            maxSum=max(maxSum,i-mpp[sum-k]);
        }
        //if sum is not present already
        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
    }
    cout<<"Length of longest subarray is: "<<maxSum;
}