#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    路径长度:
        path_len = (depth[a] - depth[LCA]) + (depth[b] - depth[LCA])

    · 边权 1 <= w <= 26，用数组统计出现次数
*/

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // build
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2] - 1; // 权重减 1，便于书写
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        int m = 32 - __builtin_clz(n);
        vector pa(n, vector<int>(m, -1));
        vector cnt(n, vector<vector<int>>(m, vector<int>(26))); // 用于统计节点路径权值
        vector<int> depth(n);

        // 更新 cnt 和 depth
        function<void(int, int)> dfs = [&](int x, int fa) -> void {
            pa[x][0] = fa;
            for (const auto& [y, w] : g[x]) {
                if (y != fa) {
                    cnt[y][0][w] = 1;
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        // LCA
        for (int j = 0; j < m - 1; ++j) {
            for (int i = 0; i < n; ++i) {
                int p = pa[i][j];
                if (p != -1) {
                    pa[i][j + 1] = pa[p][j];
                    for (int k = 0; k < 26; ++k) {
                        cnt[i][j + 1][k] = cnt[i][j][k] + cnt[p][j][k];
                    }
                }
            }
        }

        vector<int> ans;
        for (const auto& q : queries) {
            // pre_process
            int x = q[0], y = q[1];
            int cnt_w[26] {};
            int path_len = depth[x] + depth[y];
            if (depth[x] > depth[y]) {
                swap(x, y);
            }

            // 跳到相同深度
            for (int k = depth[y] - depth[x]; k; k &= k - 1) {
                int i = __builtin_ctz(k), p = pa[y][i];
                for (int j = 0; j < 26; ++j) {
                    cnt_w[j] += cnt[y][i][j];
                }
                y = p;
            }

            // 相同深度时未相遇，寻找 LCA
            if (y != x) {
                for (int j = m - 1; j >= 0; --j) {
                    int px = pa[x][j], py = pa[y][j];
                    if (px != py) {
                        for (int k = 0; k < 26; ++k) {
                            cnt_w[k] += cnt[x][j][k] + cnt[y][j][k];
                        }
                        x = px, y = py;
                    }
                }

                for (int k = 0; k < 26; ++k) {
                    cnt_w[k] += cnt[x][0][k] + cnt[y][0][k];
                }
                x = pa[x][0];
            }

            path_len -= depth[x] * 2; // 减去 depth[lca] * 2
            ans.emplace_back(path_len - *ranges::max_element(cnt_w, cnt_w + 26));
        }

        return ans;
    }
};