#include <bits/stdc++.h>

using namespace std;

class Solution {
    using PII = pair<int, int>;

public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<PII>> g(n);
        for (vector<int>& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        vector<int> dis(n, -1);
        dis[0] = 0;

        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [d, cur] = q.top();
            q.pop();

            if (d > dis[cur]) {
                continue;
            }

            for (auto& [to, w] : g[cur]) {
                int val = d + w;
                if (val < disappear[to] && (dis[to] == -1 || val < dis[to])) {
                    dis[to] = val;
                    q.emplace(val, to);
                }
            }
        }

        return dis;
    }
};