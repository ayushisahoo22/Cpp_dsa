#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter the number of rows: ";
    cin >> r;
    cout << "Enter the number of columns";
    cin >> c;
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }

    //BETTER approach
    // TC--->O(2*(r*c))
    // SC--->O(N)
    /*int row[r] = {0};
    int col[c] = {0};
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/

    //as the matrix will take time complexity of O(N^2) in any way
    //so we will optimise the space complexity
    //OPTIMAL approach
    int col0=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j!=0){
                    arr[0][j]=0;
                }else{
                    col0=0;
                }
            }
        }
    }
    //marks from (1,1) to (r-1,c-1)
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(arr[i][j]!=0){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }
    }
    //mark the first col and first row
    if(arr[0][0]==0){
        for(int j=0;j<c;j++){
            arr[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<r;i++){
            arr[i][0]=0;
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
   
}