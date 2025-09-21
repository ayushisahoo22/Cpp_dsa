#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of rows & cols: ";
    cin>>n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
    
    //Transpose of mantrix
    //diagonal elements will be at the same place
    //swap the rest [i][j] element
    // [0][1]-->[1][0]
    // [0][2]-->[2][0]
    // [0][3]-->[3][0]
    // [1][2]-->[2][1]
    // [1][3]-->[3][1]
    // [2][3]-->[3][2]
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    //reversing the transpose
    for(int i=0;i<n;i++){
        int p1=0,p2=n-1;
        while(p1<p2){
            swap(arr[i][p1],arr[i][p2]);
            p1++;p2--;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}