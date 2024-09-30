#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
    vector<int> C;

    int dfs(int x, int pa, vector<vector<int>>& g) {
        int cnt = 1;
        for (int y : g[x]) {
            if (y != pa) {
                cnt += dfs(y, x, g);
            }
        }
        return C[x] = cnt;
    }

    int dfs2(int x, int pa, vector<vector<int>>& g) {
        set<int> s;
        int res = 0;
        for (int y : g[x]) {
            if (y != pa) {
                s.emplace(C[y]);
                res += dfs2(y, x, g);
            }
        }
        if (s.size() <= 1) {
            res++;
        }
        return res;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        C.resize(n, 0);
        dfs(0, -1, g);

        return dfs2(0, -1, g);
    }
};

int main() {
    Solution sol;

    return 0;
}