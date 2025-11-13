#include <iostream>
#include <vector>
using namespace std;

//TC->O(N)
//SUITABLE FOR:
// The range of values is not too large
// The array contains the non-negative numbers

void countingSort(vector<int> &arr, int n) {
    // Step 1: Find the maximum value
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // Step 2: Create and initialize count array
    vector<int> count(maxVal + 1, 0);

    // Step 3: Store the frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Modify count array (prefix sum)
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Step 5: Build the output array (stable)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy output back to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main(){
    int n;
    cout<<"Enter the val of n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countingSort(arr, n);
    for(auto it:arr){
        cout<<it<<" ";
    }
}