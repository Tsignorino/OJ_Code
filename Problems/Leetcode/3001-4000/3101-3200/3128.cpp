#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m), cols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                rows[i]++;
                cols[j]++;
            }
        }

        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                ans += (rows[i] - 1) * (cols[j] - 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> vec {
        {1, 0, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 0}
    };
    sol.numberOfRightTriangles(vec);

    // [[1]]  0
    // [[0,0],[0,1],[1,1]]  1
    // [[0,0],[1,1],[1,0],[0,1]]    2

    return 0;
}