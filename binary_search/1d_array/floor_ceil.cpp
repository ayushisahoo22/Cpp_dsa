#include<bits/stdc++.h>
using namespace std;

// given an sorted array arr of n integers and an integer x.
// Find the floor and ceiling of x in arr[0..n-1].

int ceil(vector<int>arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    int c=-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[mid]>=x){
            c=arr[mid];
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return c;
}

int floor(vector<int>arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    int f=-1;
    while(low<=high){
        int mid=(high+low)/2;
        if(arr[mid]<=x){
            f=arr[mid];
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return f;
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
    int fl=floor(arr,k);
    int cl=ceil(arr,k);
    cout<<"floor is: "<<fl<<endl<<"ceil is: "<<cl;
}