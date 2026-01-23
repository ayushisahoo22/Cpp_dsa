#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);
        int n1 = a.size(), n2 = b.size();
        int low = 0, high = n1;
        // Binary search on the smaller array
        while (low <= high) {
            // Calculate the cut positions for both arrays
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Handle boundary elements using INT_MIN and INT_MAX
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

            // If correct partition is found
            if (l1 <= r2 && l2 <= r1) {
                // Total even => average of max left and min right
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    // Total odd => max of left half
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                // Shift left in a
                high = cut1 - 1;
            }
            else {
                // Shift right in a
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 3};
    vector<int> b = {2};
    cout << "Median is: " << sol.findMedianSortedArrays(a, b) << endl;
    return 0;
}