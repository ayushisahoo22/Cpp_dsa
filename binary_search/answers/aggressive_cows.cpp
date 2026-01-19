#include<bits/stdc++.h>
using namespace std;

// given an array 'arr' of size 'n' which denotes the position of stalls
// given an integer 'k' which denotes the number of aggressive cows.
// given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible. 
// Find the maximum possible minimum distance.

bool canBePlace(vector<int>stalls,int c,int d){
    int cow=1;
    int last=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last>=d){
            cow++;
            last=stalls[i];
        }
        if(cow>=c) return true;
    }
    return false;
}

int aggressiveCows(vector<int>stalls,int k){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[n-1]-stalls[0];
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(canBePlace(stalls,k,mid)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n,k;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter cows: ";
    cin>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=aggressiveCows(arr,k);
    cout<<ans;
}