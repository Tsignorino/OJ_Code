#include <bits/stdc++.h>

using namespace std;

class Solution {
    using min_heap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>;

public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), f;
        vector<min_heap> col_heaps(n);
        for (int i = 0; i < m; i++) {
            min_heap row_h;
            for (int j = 0; j < n; j++) {
                while (!row_h.empty() && row_h.top().second < j) { // 无法跳到第 j 列
                    row_h.pop();
                }

                auto& col_h = col_heaps[j];
                while (!col_h.empty() && col_h.top().second < i) {
                    col_h.pop();
                }

                f = i || j ? INT_MAX : 1; // 起点格子
                if (!row_h.empty()) {
                    f = row_h.top().first + 1;
                }
                if (!col_h.empty()) {
                    f = min(f, col_h.top().first + 1);
                }

                int g = grid[i][j];
                if (g && f < INT_MAX) {
                    row_h.emplace(f, g + j);
                    col_h.emplace(f, g + i);
                }
            }
        }
        return f < INT_MAX ? f : -1;
    }
};

class Solution1 {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minV;
        vector<vector<pair<int, int>>> col_stks(n);
        vector<pair<int, int>> row_stk;

        auto f = [](const auto& a, const int b) {
            return a.second > b;
        };

        for (int i = m - 1; i >= 0; --i) {
            row_stk.clear();

            for (int j = n - 1; j >= 0; --j) {
                int val = grid[i][j];
                auto& col_stk = col_stks[j];

                minV = i < m - 1 || j < n - 1 ? INT_MAX : 1;
                if (val) { // 非零值
                    auto iter = lower_bound(row_stk.begin(), row_stk.end(), j + val, f);
                    if (iter < row_stk.end()) {
                        minV = iter->first + 1;
                    }

                    iter = lower_bound(col_stk.begin(), col_stk.end(), i + val, f);
                    if (iter < col_stk.end()) {
                        minV = min(minV, iter->first + 1);
                    }
                }

                if (minV < INT_MAX) {
                    while (!row_stk.empty() && minV <= row_stk.back().first) {
                        row_stk.pop_back();
                    }
                    row_stk.emplace_back(minV, j);

                    while (!col_stk.empty() && minV <= col_stk.back().first) {
                        col_stk.pop_back();
                    }
                    col_stk.emplace_back(minV, i);
                }
            }
        }

        return minV == INT_MAX ? -1 : minV;
    }
};

int main() {
    vector<vector<int>> grid {
        {3, 4, 2, 1},
        {4, 2, 3, 1},
        {2, 1, 0, 0},
        {2, 4, 0, 0}
    };

    Solution sol;
    cout << sol.minimumVisitedCells(grid) << "\n";

    return 0;
}

//* 超时
class mySolution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector vis(m, vector<int>(n));

        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 1);
        vis[0][0] = 1;
        while (!q.empty()) {
            auto [x, y, cnt] = q.front();
            q.pop();
            if (x == m - 1 && y == n - 1) {
                return cnt;
            }

            for (int i = x + 1; i < min(m, x + grid[x][y] + 1); ++i) {
                if (!vis[i][y]) {
                    q.emplace(i, y, cnt + 1);
                    vis[i][y] = 1;
                }
            }
            for (int j = y + 1; j < min(n, y + grid[x][y] + 1); ++j) {
                if (!vis[x][j]) {
                    q.emplace(x, j, cnt + 1);
                    vis[x][j] = 1;
                }
            }
        }

        return -1;
    }
};