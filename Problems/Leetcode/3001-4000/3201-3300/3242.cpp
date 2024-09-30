#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

const vector<vector<int>> dir1 {
    {-1, 0 },
    {1,  0 },
    {0,  -1},
    {0,  1 }
};

const vector<vector<int>> dir2 {
    {-1, -1},
    {-1, 1 },
    {1,  -1},
    {1,  1 }
};

class neighborSum {
private:
    int n;
    vector<vector<int>> g;
    vector<pair<int, int>> pos;

    bool check(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

    int calc(int val, const vector<vector<int>>& dir) {
        auto& [x, y] = pos[val];
        int sum = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (check(nx, ny)) {
                sum += g[nx][ny];
            }
        }
        return sum;
    }

public:
    neighborSum(vector<vector<int>>& grid) : n(grid.size()), g(grid), pos(n * n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) { return calc(value, dir1); }

    int diagonalSum(int value) { return calc(value, dir2); }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
