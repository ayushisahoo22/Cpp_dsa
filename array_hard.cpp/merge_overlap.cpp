#include <bits/stdc++.h>
using namespace std;

//TC->O(N^2)   SC->O(N)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int n = intervals.size();
    for (int i = 0; i < n; ) {
        // Start of current merged interval
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Merge with all overlapping intervals
        int j = i + 1;
        while (j < n && intervals[j][0] <= end) {
            // Update end to the maximum of current end and overlapping interval's end
            end = max(end, intervals[j][1]);
            j++;
        }
        ans.push_back({start, end});

        // Move to the next non-overlapping interval
        i = j;
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = merge(intervals);

    for (auto interval : result) {
        cout <<"["<< interval[0]<<","<<interval[1]<<"] ";
    }
    return 0;
}