#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    static constexpr int dir[4][2] = {
        {-1, 0 },
        {0,  -1},
        {1,  0 },
        {0,  1 }
    };

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();

        vector dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = grid[0][0];

        deque<pair<int, int>> q;
        q.emplace_front(0, 0);

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();

            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int g = grid[nx][ny];
                    if (dis[x][y] + g < dis[nx][ny]) {
                        dis[nx][ny] = dis[x][y] + g;
                        g == 0 ? q.emplace_front(nx, ny) : q.emplace_back(nx, ny);
                    }
                }
            }
        }

        return dis[n - 1][m - 1] < health;
    }
};

int main() {
    Solution sol;

    return 0;
}