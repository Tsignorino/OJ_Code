#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals);

        // int start = intervals[0][0], end = intervals[0][1];
        // vector<vector<int>> ans;
        // for (int i = 1; i < intervals.size(); ++i) {
        //     if (end >= intervals[i][0]) {
        //         end = max(end, intervals[i][1]);
        //     } else {
        //         ans.emplace_back(vector {start, end});
        //         start = intervals[i][0], end = intervals[i][1];
        //     }
        // }
        // ans.emplace_back(vector {start, end});

        vector<vector<int>> ans;
        for (auto& p : intervals) {
            if (!ans.empty() && p[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], p[1]);
            } else {
                ans.emplace_back(p);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}