#include<bits/stdc++.h>
using namespace std;

// Given the array nums after the possible rotation and an integer target,
// For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2]
// return the index of target if it is in nums, or -1 if it is not in nums.

int rotatedSearch(vector<int>arr,int k){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k) return mid;

        //left is sorted
        if(arr[mid]>=arr[low]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
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
    int ans=rotatedSearch(arr,k);
    cout<<ans;
}