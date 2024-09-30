#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        vector<unordered_set<int>> g(n);
        for (auto& edge : edges) {
            int v1 = edge[0], v2 = edge[1];
            g[v1].insert(v2);
            g[v2].insert(v1);
        }

        // Topo
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1) {
                q.emplace(i);
            }
        }

        while (n > 2) {
            int s = q.size();
            n -= s;
            for (int i = 0; i < s; ++i) {
                int v = q.front();
                q.pop();

                for (int t : g[v]) {
                    g[t].erase(v);
                    if (g[t].size() == 1) {
                        q.emplace(t);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.emplace_back(q.front());
            q.pop();
        }
        return ans;
    }
};