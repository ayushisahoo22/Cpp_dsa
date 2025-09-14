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
    /*vector<int> ans(n);
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
    }*/

    //if occurence are not equal
    vector<int>pos;
    vector<int> neg;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            ans[2*i]=pos[i];
            ans[2*i+1]=neg[i];
        }
        int ind=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            ans[ind]=pos[i];
            ind++;
        }
    }else{
        for(int i=0;i<pos.size();i++){
            ans[2*i]=pos[i];
            ans[2*i+1]=neg[i];
        }
        int ind=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            ans[ind]=neg[i];
            ind++;
        }
    }
    // for(int i=0;i<pos.size();i++){
    //     cout<<pos[i]<<" ";
    // }
    // for(int i=0;i<neg.size();i++){
    //     cout<<neg[i]<<" ";
    // }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}