#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowMax(n), colMax(n);
        for (int i = 0; i < n; ++i) {
            int rmx = 0, cmx = 0;
            for (int j = 0; j < n; ++j) {
                rmx = max(rmx, grid[i][j]);
                cmx = max(cmx, grid[j][i]);
            }
            rowMax[i] = rmx, colMax[i] = cmx;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}