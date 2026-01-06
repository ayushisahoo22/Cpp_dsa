#include<bits/stdc++.h>
using namespace std;

//find the count of rotation in the sorted array
// [4,5,6,7,0,1,2,3]
// Result: 4
// The original array should be [0,1,2,3,4,5,6,7]. the array has been rotated 4 times.

int cntRotated(vector<int>arr){
    int n=arr.size();
    int low=0,high=n-1;
    int ans=INT_MAX;
    int indx=-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[mid]>=arr[low]){
            if(arr[low]<ans){
                ans=arr[low];
                indx=low;
            }
            low=mid+1;
        }else{
            if(arr[mid]<ans){
                ans=arr[mid];
                indx=mid;
            }
            high=mid-1;
        }
    }
    return indx;
}


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
    int ans=cntRotated(arr);
    cout<<ans;
}