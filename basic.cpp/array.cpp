#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of array: ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Printing the elements: ";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}