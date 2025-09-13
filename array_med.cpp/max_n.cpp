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
    /*map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>n/2){
            cout<<it.first;
        }
    }*/

    //optimal approach
    //MOORE'S VOTING ALGO

    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el=arr[i];
            cnt=1;
        }else if(arr[i]==el){
            cnt++;
        }else{cnt--;}
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el){
            count++;
        }
    }
    if(count>n/2){
        cout<<el;
    }else{
        cout<<"No such element present in the array";
    }
}
