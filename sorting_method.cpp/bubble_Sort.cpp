//bubble sort
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int didSwap=0;     //for optimisation:O(N) for best soln
    for(int i=0;i<=n-1;i++){
        for(int j =0;j<=n-2;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwap++;
            }
        }
        cout<<"runs\n";   //to check runs of first for loop
        if(didSwap==0){
            break;
        }
    }
     
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//bubbles srt 2
// int main(){
//     int n;
//     cout<<"Enter the n: ";
//     cin>>n;
//     int arr[100];
//     cout<<"Enter the elements of array"<<endl;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<=n-1;i++){
//         for(int j =i+1;j<=n-1;j++){
//             if(arr[j]<arr[j-1]){
//                 int temp=arr[j-1];
//                 arr[j-1]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
     
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
