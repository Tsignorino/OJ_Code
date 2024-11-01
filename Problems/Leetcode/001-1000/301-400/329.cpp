#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    static constexpr int dir4[4][2] = {
        {-1, 0 },
        {0,  -1},
        {1,  0 },
        {0,  1 }
    };

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // 有向无环图
        int n = matrix.size(), m = matrix[0].size();

        auto check = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        //* 拓扑
        vector Out(n, vector<int>(m));
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dir4[k][0], ny = y + dir4[k][1];
                    if (check(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
                        Out[x][y]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (Out[x][y] == 0) {
                    q.emplace(x, y);
                }
            }
        }

        int ans = 0;
        while (!q.empty()) {
            ans++;
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dir4[k][0], ny = y + dir4[k][1];
                    if (check(nx, ny) && matrix[nx][ny] < matrix[x][y]) {
                        if (--Out[nx][ny] == 0) {
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }
        return ans;

        //* dfs + memo
        // vector memo(n, vector<int>(m));
        // auto dfs = [&](auto&& self, int x, int y) {
        //     int& res = memo[x][y];
        //     if (res != 0) {
        //         return res;
        //     }
        //
        //     res++;
        //     for (int k = 0; k < 4; ++k) {
        //         int nx = x + dir4[k][0], ny = y + dir4[k][1];
        //         if (check(nx, ny) && matrix[nx][ny] < matrix[x][y]) {
        //             memo[x][y] = max(memo[x][y], self(self, nx, ny) + 1);
        //         }
        //     }
        //     return res;
        // };
        //
        // int ans = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         ans = max(ans, dfs(dfs, i, j));
        //     }
        // }
        // return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}