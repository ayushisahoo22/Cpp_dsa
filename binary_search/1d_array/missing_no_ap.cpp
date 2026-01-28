#include<bits/stdc++.h>
using namespace std;

//find missing no in an ap

int missingNo(vector<int>arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int d=(arr[n-1]-arr[0])/n;
    while(low<=high){
        int mid=(low+high)/2;
        int no=arr[0]+mid*d;
        if(arr[mid]==no){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return arr[0]+low*d;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=missingNo(arr);
    cout<<ans;
}