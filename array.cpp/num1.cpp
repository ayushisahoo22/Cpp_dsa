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
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            cout<<"Only one time occurring number is: "<<it.first;
        }
    }
}