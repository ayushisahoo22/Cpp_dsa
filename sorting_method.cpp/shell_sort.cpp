#include <bits/stdc++.h>
using namespace std;

//In shell sort the values will be check on the gaps and gradually the gap will decrease after it reach the n-1 ele
//In gap=1 it will behave as insertion sort
//But as we have already checked the swaps at gap/8,gap/4,gap/2... 
//the last one (gap=1) will take less swaps as compared to the swaps in insertion sort

//time complexity depends on gap sequence
//here TC->O(N^2)
void shellSort(vector<int> &arr,int n){
    int gap=n/2;
    while(gap>0){
        for(int j=gap;j<n;j++){
            //if swap occurs b/w i and i+gap then only we will check for the values at indx i-gap
            for(int i=j-gap;i>=0;i=i-gap){
                //using i+gap and not j bcz if we require to swap for i-gap and i then j will provide wrong swap
                if(arr[i+gap]>arr[i]){
                    break;
                }else{
                    swap(arr[i+gap],arr[i]);
                }
            }
        }
        gap/=2;
    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shellSort(arr,n);
    for(auto it:arr){
        cout<<it<<" ";
    }
}