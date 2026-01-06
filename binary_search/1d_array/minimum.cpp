#include<bits/stdc++.h>
using namespace std;

//find the minimum element in rotated sorted array

int minimumRotated(vector<int>arr){
    int n=arr.size();
    int low=0,high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[mid]>=arr[low]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }else{
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
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
    int ans=minimumRotated(arr);
    cout<<ans;
}