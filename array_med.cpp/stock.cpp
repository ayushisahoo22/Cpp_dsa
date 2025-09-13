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
    int buy=INT_MAX;
    int stock=0;
    for(int i=0;i<n;i++){
        if(arr[i]<buy){
            buy=arr[i];
        }else if(arr[i]-buy>stock){
            stock=arr[i]-buy;
        }
    }
    cout<<stock;
    return 0;
    
}