#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
static constexpr int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        vector dis(n, vector(50, vector<int>(50, -1)));

        // 计算步数
        for (int i = 0; i < n; ++i) {
            int px = positions[i][0], py = positions[i][1];
            dis[i][px][py] = 0;
            vector<pair<int, int>> q {
                {px, py}
            };
            for (int step = 1; !q.empty(); step++) {
                vector<pair<int, int>> tmp;
                for (auto& [qx, qy] : q) {
                    for (int k = 0; k < 8; ++k) {
                        int x = qx + dx[k], y = qy + dy[k];
                        if (x >= 0 && x < 50 && y >= 0 && y < 50 && dis[i][x][y] < 0) {
                            dis[i][x][y] = step;
                            tmp.emplace_back(x, y);
                        }
                    }
                }
                q = std::move(tmp);
            }
        }

        positions.push_back({kx, ky});
        vector memo(n + 1, vector<int>(1 << n, -1));
        int u = (1 << n) - 1;
        auto dfs = [&](auto&& dfs, int i, int mask) -> int {
            if (mask == 0) {
                return 0;
            }
            int& res = memo[i][mask];
            if (res != -1) {
                return res;
            }
            int x = positions[i][0], y = positions[i][1];
            if (__builtin_parity(u ^ mask) == 0) {
                for (int j = 0; j < n; ++j) {
                    if (mask >> j & 1) {
                        res = max(res, dfs(dfs, j, mask ^ (1 << j)) + dis[j][x][y]);
                    }
                }
            } else {
                res = numeric_limits<int>::max();
                for (int j = 0; j < n; ++j) {
                    if (mask >> j & 1) {
                        res = min(res, dfs(dfs, j, mask ^ (1 << j)) + dis[j][x][y]);
                    }
                }
            }
            return res;
        };
        return dfs(dfs, n, u);
    }
};

int main() {
    Solution sol;

    return 0;
}