#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r1 = INT_MAX, r2 = -1;
        int c1 = INT_MAX, c2 = -1;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    r1 = min(r1, i);
                    r2 = max(r2, i);
                    c1 = min(c1, j);
                    c2 = max(c2, j);
                }
            }
        }
        return (r2 - r1 + 1) * (c2 - c1 + 1);
    }
};

int main() {
    Solution sol;

    return 0;
}