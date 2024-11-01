#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        // build
        int n = edges.size();
        vector<vector<int>> g(n + 1);
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        unordered_map<i64, int> ump; // attention 2
        for (auto& guess : guesses) {
            ump[((i64) guess[0] << 32) + guess[1]]++; // attention 1
        }

        int cnt = 0;
        function<void(int, int)> dfs = [&](int x, int parent) -> void {
            for (int& y : g[x]) {
                if (y != parent) {
                    cnt += ump[((i64) x << 32) + y];

                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        // reroot
        int ans = 0;
        function<void(int, int, int)> reroot = [&](int i, int parent, int cnt) -> void {
            ans += cnt >= k;

            for (int& j : g[i]) {
                if (j != parent) {
                    reroot(j, i, cnt - ump[((i64) i << 32) + j] + ump[((i64) j << 32) + i]);
                }
            }
        };
        reroot(0, -1, cnt);
        return ans;
    }
};