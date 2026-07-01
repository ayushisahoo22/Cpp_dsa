#include<bits/stdc++.h>
using namespace std;

int minPlatforms(int arr[],int dep[],int n){
    sort(arr,arr+n);
    sort(dep,dep+n);
    int ans=1;
    int cnt=1;
    int i=1,j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            cnt++;
            i++;
        }else{
            cnt--;
            j++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}

int main(){
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans=minPlatforms(arr,dep,n);
    cout<<ans;
}