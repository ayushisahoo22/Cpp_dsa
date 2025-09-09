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
    //storing values in temp
    int temp[100];
    int j=0;
    for(int i=n-k;i<n;i++){
        temp[j]=arr[i];
        j++;
    }
    //shifting of the array
    for(int i=n-1;i>=k;i--){
        arr[i]=arr[i-k];
    }
    //merging temp to arr
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
    //displaying values
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}