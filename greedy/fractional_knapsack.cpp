#include<bits/stdc++.h>
using namespace std;

double knapsack(vector<vector<int>>&arr,int capacity,int n){
    sort(begin(arr),end(arr),[](auto a,auto b){
        double r1=(double)a[0]/(double) a[1];
        double r2=(double)b[0]/(double) b[1];
        return r1>r2;
    });

    int i=0;
    double ans=0;
    while(i<arr.size() && capacity>0){
        if(capacity>arr[i][1]){
            ans+=arr[i][0];
            capacity-=arr[i][1];
        }else{
            double ratio=(double)capacity/(double)arr[i][1];
            ans+= ratio*arr[i][0];
            capacity=0;
        }
        i++;
    }
    return ans;
}

int main(){
    int n,capacity;
    cout<<"Enter n and capacity: ";
    cin>>n>>capacity;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++){
        int p,w;
        cout<<"Enter p and wt of "<<i+1<<" element";
        cin>>p>>w;
        arr.push_back({p,w});
    }

    double ans=knapsack(arr,capacity,n);
    cout<<ans;
    return 0;
}