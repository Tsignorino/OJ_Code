#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        ranges::sort(ranges);
        int ans = 1;
        int end = -1;
        for (vector<int>& p : ranges) {
            if (p[0] > end) {
                ans = ans * 2 % 1'000'000'007;
            }
            end = max(end, p[1]);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> nums {
        {34, 56},
        {28, 29},
        {12, 16},
        {11, 48},
        {28, 54},
        {22, 55},
        {28, 41},
        {41, 44}
    };

    Solution sol;
    cout << sol.countWays(nums);

    return 0;
}