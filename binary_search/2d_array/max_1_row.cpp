#include<bits/stdc++.h>
using namespace std;

// You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s.
// All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones.
// Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

class Solution {
public:
    int lowerBound(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n; 
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;       
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }

    // Find row with max number of 1s
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            int cnt_ones = m - lowerBound(matrix[i], m, 1);
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;

    Solution obj;
    cout << "The row with maximum no. of 1's is: " << obj.rowWithMax1s(matrix, n, m) << '\n';
}