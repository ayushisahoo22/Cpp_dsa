#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the value of target: ";
    cin>>target;
    /*
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        int x=target-arr[i];
        if(mpp.find(x)!=mpp.end()){
            cout<<mpp[x]<<" "<<i;
            return 0;
        }
        mpp[arr[i]]=i;
    }
    cout<<"Not found";
    return 0;*/

    //using two pointer approach
    int s;int e=n-1;
    for(s=0;s<=e;s++){
        if(arr[s]+arr[e]==target){
            cout<<s<<" "<<e;
            return 0;
        }else{
            e--;
        }
    }
}