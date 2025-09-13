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
     
    //if positive numbers occurence are equal to negative numbers occurence
    vector<int> ans(n);
    int pos=0,neg=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans[pos]=arr[i];
            pos+=2;
        }else{
            ans[neg]=arr[i];
            neg+=2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}