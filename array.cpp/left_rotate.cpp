#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    k=k%n;
    int temp[100];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    int j=0;
    for(int i=n-k;i<n;i++){
        arr[i]=temp[j];
        j++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}