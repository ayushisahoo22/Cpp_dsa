#include <bits/stdc++.h>
using namespace std;

// Class to find the k-th missing number in a sorted array

//tc->O(N)

class MissingKFinder {
public:
    // Function to find the k-th missing number
    int missingK(vector<int> vec, int n, int k) {
        for (int i = 0; i < n; i++) {
            if (vec[i] <= k) {
                k++;  // If current number is less than or equal to k, increment k
            } else {
                break; // Stop when we reach a number greater than k
            }
        }
        return k;  // Return the final value of k which is the missing number
    }
};

int main() {
    vector<int> vec = {4, 7, 9, 10}; 
    int n = vec.size();           
    int k = 4;                       // We are looking for the 4th missing number

    MissingKFinder finder;               // Create object
    int ans = finder.missingK(vec, n, k);  // Call method

    cout << "The missing number is: " << ans << "\n";  // Output the result
    return 0;
}