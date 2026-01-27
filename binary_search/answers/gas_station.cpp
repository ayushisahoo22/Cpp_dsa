#include<bits/stdc++.h>
using namespace std;

// given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.
// given an integer ‘k’. You have to place 'k' new gas stations on the X-axis.
// You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.
// Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.Find the minimum value of ‘dist’.

//better approach
// long double minDistance(vector<int> &arr,int k){
//     int n=arr.size();
//     vector<int>howmany(n-1,0);
//     priority_queue<pair<long double,int>>pq;
//     for(int i=0;i<n-1;i++){
//         pq.push({arr[i+1]-arr[i],i});
//     }
//     for(int i=1;i<=k;i++){
//         auto tp=pq.top();
//         pq.pop();
//         int segmentInd=tp.second;
//         howmany[segmentInd]++;
//         long double totalDist=arr[segmentInd+1]-arr[segmentInd];
//         long double newLen=totalDist/(howmany[segmentInd]+1);
//         pq.push({newLen,segmentInd});
//     }
//     return pq.top().first;
// }

int numberOfGasStat(vector<int>arr,long double dist){
    int n=arr.size();
    int cnt=0;
    for(int i=1;i<n;i++){
        int no=(arr[i]-arr[i-1])/dist;
        if((arr[i]-arr[i-1])== no*dist){
            no--;
        }
        cnt+=no;
    }
    return cnt;
}

long double minDistance(vector<int>&arr , int k){
    int n=arr.size();
    long double low=0,high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,(long double)arr[i+1]-arr[i]);
    }
    long double diff=1e-6;
    while(high-low>diff){
        long double mid=(low+high)/2.0;
        int n=numberOfGasStat(arr,mid);
        if(n>k) low=mid;
        else high=mid;
    }
    return high;
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
    long double ans=minDistance(arr,k);
    cout<<ans;
}