#include <iostream>
using namespace std;
//function for finding partition index
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    //for getting correct position of pivot
    int t=arr[j];
    arr[j]=arr[low];
    arr[low]=t;
    return j;
}
//fuction for quick sort
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pIndx= partition(arr,low,high);
        quickSort(arr,low,pIndx-1);
        quickSort(arr,pIndx+1,high);
    }
}

int main(){
    //can take user input array
    int arr[]={4,6,2,5,7,9,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}