#include<bits/stdc++.h>
using namespace std;

//find nth root of m
//eg 3rd root of 27=3,  4rth root of 69 doesn't exists (-1)

int nthRoot(int n,int m){
    int low=1;
    int high=m;
    while(low<=high){
        int mid = (low+high)/2;
        long long ans=1;
        for(int i=0;i<n;i++){
            ans*=mid;
            if(ans>m) break;
        }
        if(ans==m) return mid;
        if(ans<mid) low=mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    int ans=nthRoot(n,m);
    cout<<ans;
}
