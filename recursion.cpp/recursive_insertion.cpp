#include <iostream>
using namespace std;
void insertionSort(int arr[],int s,int e){
    if(s>=e) return;
    int j=s;
    while(j>0 && arr[j]<arr[j-1]){
        
        int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
        j--;
    }
    insertionSort(arr,s+1,e);
}
int main(){
    //can take user input here
    int arr[]={13,9,52,24,20,47};
    int end= sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,0,end);
    cout<<"After Sorting"<<endl;
    for(int i=0;i<end;i++){
        cout<<arr[i]<<" ";
    }
}