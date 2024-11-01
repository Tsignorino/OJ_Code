#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dx[3] = {-1, 0, 1}, dy[3] = {1, 1, 1};

public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        /* DFS
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            ans = max(ans, j);
            if (ans == n - 1) {
                return;
            }

            for (int k = max(i - 1, 0); k < min(i + 2, m); ++k) {
                if (grid[k][j + 1] > grid[i][j]) {
                    dfs(k, j + 1);
                }
            }
            grid[i][j] = 0;
        };

        for (int i = 0; i < m; ++i) {
            dfs(i, 0);
        }

        return ans;
        */

        //* BFS: 可以使用队列和 vis 数组标记，让未入队的元素入队（也可以对元素取反，优化空间）
        for (vector<int>& r : grid) {
            r[0] *= -1;
        }

        for (int j = 0; j < n - 1; ++j) {
            bool flag = false;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] > 0) {
                    continue;
                }
                for (int k = max(i - 1, 0); k < min(i + 2, m); ++k) {
                    if (grid[k][j + 1] > -grid[i][j]) {
                        grid[k][j + 1] *= -1;
                        flag = true;
                    }
                }
            }

            if (flag == false) {
                return j;
            }
        }

        return n - 1;

        /*
        vector f(m, vector<int>(n)), vis(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            vis[i][1] = 1;
        }

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                for (int k = 0; k < 3; ++k) {
                    int x = i - dx[k], y = j - dy[k];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[i][j] <= grid[x][y] || !vis[x][y]) {
                        continue;
                    }

                    f[i][j] = max(f[i][j], f[x][y] + 1);
                    vis[i][j] = 1;
                }

                ans = max(ans, f[i][j]);
            }
        }

        return ans;
        */
    }
};