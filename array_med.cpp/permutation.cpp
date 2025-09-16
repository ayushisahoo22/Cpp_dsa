#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the vector ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ind=-1;
    //to find break point
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    //if break point does not exist
    //to reverse the whole array
    if(ind==-1){
        reverse(arr.begin(),arr.end());
    }
    
    //find next greater ele then swap
    for(int i=n-1;i>ind;i++){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    //reverse the half array
    reverse(arr.begin()+ind+1,arr.end());

    //print the next permutation
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}