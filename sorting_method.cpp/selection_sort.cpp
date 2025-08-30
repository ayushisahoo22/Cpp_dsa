#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//selection sort
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j =i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min =j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}