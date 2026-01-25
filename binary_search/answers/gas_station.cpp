#include<bits/stdc++.h>
using namespace std;

// given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.
// given an integer ‘k’. You have to place 'k' new gas stations on the X-axis.
// You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.
// Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.Find the minimum value of ‘dist’.

//better approach
long double minDistance(vector<int> &arr,int k){
    int n=arr.size();
    vector<int>howmany(n-1,0);
    priority_queue<pair<long double,int>>pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int i=1;i<=k;i++){
        auto tp=pq.top();
        pq.pop();
        int segmentInd=tp.second;
        howmany[segmentInd]++;
        long double totalDist=arr[segmentInd+1]-arr[segmentInd];
        long double newLen=totalDist/(howmany[segmentInd]+1);
        pq.push({newLen,segmentInd});
    }
    return pq.top().first;
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