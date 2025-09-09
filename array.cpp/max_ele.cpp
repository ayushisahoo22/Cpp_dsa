#include <iostream>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of array ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"Max element of the array is: "<<max;
}
