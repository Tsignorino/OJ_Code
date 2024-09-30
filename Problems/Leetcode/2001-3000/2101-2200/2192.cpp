#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (vector<int>& vec : edges) {
            g[vec[0]].emplace_back(vec[1]);
        }

        vector<vector<int>> ans(n);
        vector<int> vis(n, -1);
        int pa;
        function<void(int)> dfs = [&](int x) -> void {
            vis[x] = pa;
            for (int y : g[x]) {
                if (vis[y] != pa) {
                    ans[y].emplace_back(pa);
                    dfs(y);
                }
            }
        };

        for (pa = 0; pa < n; ++pa) {
            dfs(pa);
        }
        return ans;
    }

public:
    vector<vector<int>> getAncestors_1(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (vector<int>& vec : edges) {
            g[vec[1]].emplace_back(vec[0]);
        }

        vector<int> vis(n);
        function<void(int)> dfs = [&](int node) -> void {
            vis[node] = true;
            for (int& v : g[node]) {
                if (!vis[v]) {
                    dfs(v);
                }
            }
        };

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            // vis.clear();
            // vis.resize(n);
            ranges::fill(vis, false);
            dfs(i);
            vis[i] = false;

            for (int j = 0; j < n; ++j) {
                if (vis[j]) {
                    ans[i].emplace_back(j);
                }
            }
        }
        return ans;
    }
};