#include<bits/stdc++.h>
using namespace std;

// array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].

int lb(vector<int>arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

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

vector<int> firstAndLast(vector<int>arr,int k){
    int lower=lb(arr,k);
    if(lower==arr.size() || arr[lower]!=k){
        return {-1,-1};
    }
    return{lower,ub(arr,k)-1};
}

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
    vector<int>result=firstAndLast(arr,k);
    for(auto it:result){
        cout<<it<<" ";
    }
}