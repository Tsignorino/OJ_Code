#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        vector<vector<int>> g1(n);
        for (auto& e : edges1) {
            int u = e[0], v = e[1];
            g1[u].push_back(v);
            g1[v].push_back(u);
        }

        int m = edges2.size() + 1;
        vector<vector<int>> g2(m);
        for (auto& e : edges2) {
            int u = e[0], v = e[1];
            g2[u].push_back(v);
            g2[v].push_back(u);
        }

        auto dfs = [&](auto&& dfs, vector<vector<int>>& g, int u, int pa, int depth, int k) -> int {
            if (depth > k) {
                return 0;
            }
            int cnt = 1;
            for (int& v : g[u]) {
                if (v == pa) {
                    continue;
                }
                cnt += dfs(dfs, g, v, u, depth + 1, k);
            }
            return cnt;
        };

        int mx = 0;
        for (int i = 0; i < m; ++i) {
            mx = max(mx, dfs(dfs, g2, i, -1, 0, k - 1));
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = dfs(dfs, g1, i, -1, 0, k) + mx;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> edges1 {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4}
    };
    vector<vector<int>> edges2 {
        {0, 1},
        {0, 2},
        {0, 3},
        {2, 7},
        {1, 4},
        {4, 5},
        {4, 6}
    };
    sol.maxTargetNodes(edges1, edges2, 2);

    return 0;
}