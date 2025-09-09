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

    //by using swap only
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            if(i>j){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                j++;
            }
        }
    }

    /*
    int size=sizeof(arr)/sizeof(arr[0]);
    int count=0;
    //for storing elements from arr to temp
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }else if(arr[i]==0){
            count++;
        }
    }
    //for accessing values of temp to front
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    //for giving the 0 at the end
    for(int i=n-count;i<n;i++){
        arr[i]=0;
    }*/
   
    //displaying the arr
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}