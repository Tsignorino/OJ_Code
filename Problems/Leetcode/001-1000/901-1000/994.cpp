#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

static constexpr int dir4[4][2] = {
    {-1, 0 },
    {0,  -1},
    {1,  0 },
    {0,  1 }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.emplace_back(i, j);
                }
            }
        }

        int ans = -1;
        while (!q.empty()) {
            ans++;
            vector<pair<int, int>> nxt;
            for (auto& [x, y] : q) {
                for (auto d : dir4) {
                    int i = x + d[0], j = y + d[1];
                    if (0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1) {
                        fresh--;
                        grid[i][j] = 2;
                        nxt.emplace_back(i, j);
                    }
                }
            }
            q = std::move(nxt);
        }

        return fresh ? -1 : max(ans, 0);
    }
};

int main() {
    Solution sol;

    return 0;
}