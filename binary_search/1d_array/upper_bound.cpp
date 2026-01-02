#include<bits/stdc++.h>
using namespace std;

// The upper bound is the smallest index, ind, where arr[ind] > x
// if any such index is not found the lower bound algorithm returns n i.e. size of the given array.

int ub(vector<int>arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

//direct
//ub=upper_bound(arr.begin(),arr.end(),x);

int main(){
    int n,k;
    cout<<"Enter n and x: ";
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=ub(arr,k);
    cout<<ans;
}