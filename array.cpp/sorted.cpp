#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[100];
    int n;
    cout << "Enter the size of array ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //for increasing order only like 1,2 3,4...
    // bool isSort=true;
    // for(int i=0;i<n;i++){
    //     if(arr[i]>arr[i+1]){
    //         isSort=false;
    //         break;
    //     }
    // }
    // if(isSort){cout<<"sorted";}
    // else{cout<<"not sorted";}


    //for non decreasing order where elements are rotated like 4 5 6 1 2...   (rotated sorted array)
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[(i+1)%n]){
            count++;
        }
    }
    if(count>1){cout<<"not sorted";}
    else{cout<<"sorted";}
}
