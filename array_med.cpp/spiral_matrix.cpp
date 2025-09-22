#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of rows & cols: ";
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
    int top=0 ,bottom=n-1,left=0,right=n-1;
    while(left<=right && top<=bottom){
        //right
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        //bottom
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        //left
        //if is added for edge case if there is only one row in array
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        //top
        //if is added for edge case if there is only one column in array
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }  
    }
}