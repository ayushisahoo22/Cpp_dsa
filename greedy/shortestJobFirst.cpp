#include<bits/stdc++.h>
using namespace std;

int shortestJobF(vector<int>&arr,int n){
    sort(arr.begin(),arr.end());
    int total=0;
    int sum=arr[0];
    for(int i=1;i<n;i++){
        total+=sum;
        sum+=arr[i];
    }
    return total/arr.size();
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
    int ans=shortestJobF(arr,n);
    cout<<ans;
    return 0;
}