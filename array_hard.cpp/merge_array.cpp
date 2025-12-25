#include <bits/stdc++.h>
using namespace std;

//merge two SORTED array 

// void merge(vector<int>&arr1,vector<int>&arr2,int n,int m){
//     int left=n-1;
//     int right=0;
//     while(left>=0 && right<n){
//         if(arr1[left]>arr2[right]){
//             swap(arr1[left],arr2[right]);
//             left--;
//             right++;
//         }else{
//             break;
//         }
//     }
//     sort(arr1.begin(),arr1.end());
//     sort(arr2.begin(),arr2.end());
// }

//using shell sort(gap) method
void swapGreat(vector<int>&arr1,vector<int>&arr2,int left,int right){
    if(arr1[left]>arr2[right]){
        swap(arr1[left],arr2[right]);
    }
}

void merge(vector<int>&arr1,vector<int>&arr2,int n,int m){
    int len=n+m;
    int gap=len/2;   //(len/2)+(len%2)= ceil of 4.5(4+1=5)
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            //arr1 and arr2
            if(left<n && right>=n){
                swapGreat(arr1,arr2,left,right-n);
            }
            
            //arr2 and arr2
            else if(left>=n){
                swapGreat(arr2,arr2,left-n,right-n);
            }

            //arr1 and arr1
            else{
                swapGreat(arr1,arr1,left,right);
            }
            left++,right++;
        }
        gap/=2;
    }
}

int main(){
    vector<int> arr1={1,3,5,7};
    vector<int> arr2={0,2,6,8,9};
    int n=4; //size of arr1
    int m=5; //size of arr2
    merge(arr1,arr2,n,m);
    
    //after func call it will hold the n smallest element
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    //it will hold the m smallest element
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
}