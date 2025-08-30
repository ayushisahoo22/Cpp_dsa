#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Reverse of an array
//1---> By using two arguments(WITH THE HELP OF i,n)
// void rev(int arr[],int i,int n){
//     if(i>=n) return;
//     swap(arr[i],arr[n]);
//     rev(arr,i+1,n-1);

// }
// int main(){
//     int arr[5]={7,6,1,8,2};
//     int n=sizeof(arr)/sizeof(arr[0]) ;
//     rev(arr,0,n-1);
//     cout<<"[";
//     for(int i=0;i<n;i++){
        
//         cout<<arr[i]<<" ";
        
//     }
//     cout<<"]";
// }

//2---> By using one argument(WITH THE HELP OF i ONLY)
void rev(int arr[],int i,int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    rev(arr,i+1,n);
}
int main(){
    int arr[5]={7,6,1,8,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    rev(arr,0,n);
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]";
}
