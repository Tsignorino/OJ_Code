#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        auto dijk = [&](int s) -> vector<long long> {
            vector<long long> dis(n, LLONG_MAX);
            dis[s] = 0;

            using PLI = pair<long long, int>;
            priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
            pq.emplace(0, s);
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (dis[u] != d) {
                    continue;
                }
                for (auto [v, w] : g[u]) {
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        pq.emplace(dis[v], v);
                    }
                }
            }
            return dis;
        };

        vector<bool> ans(edges.size());
        auto s = dijk(0);
        long long dis = s[n - 1];
        if (dis == LLONG_MAX) {
            return ans;
        }

        auto t = dijk(n - 1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (s[u] + t[v] + w == dis || s[v] + t[u] + w == dis) {
                ans[i] = true;
            }
        }

        return ans;
    }
};

class Solution_1 {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> g(n);
        for (int i = 0; i < edges.size(); ++i) {
            vector<int>& e = edges[i];
            int u = e[0], v = e[1], w = e[2];
            g[u].emplace_back(v, w, i);
            g[v].emplace_back(u, w, i);
        }

        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;

        using PLI = pair<long long, int>;
        priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
        pq.emplace(0, 0); // dis[k], k
        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();

            if (d > dis[cur]) {
                continue;
            }
            for (auto& [to, w, _] : g[cur]) {
                if (dis[to] > d + w) {
                    dis[to] = d + w;
                    pq.emplace(dis[to], to);
                }
            }
        }

        vector<bool> ans(edges.size());
        if (dis[n - 1] == LLONG_MAX) {
            return ans;
        }

        // DFS
        // vector<int> vis(n);
        // function<void(int)> dfs = [&](int y) {
        //     vis[y] = true;
        //     for (auto& [x, w, i] : g[y]) {
        //         if (dis[x] + w != dis[y]) {
        //             continue;
        //         }

        //         ans[i] = true;
        //         if (!vis[x]) {
        //             dfs(x);
        //         }
        //     }
        // };
        // dfs(n - 1);

        // BFS
        vector<int> vis(n);
        queue<int> q;
        q.emplace(n - 1);
        while (!q.empty()) {
            int y = q.front();
            vis[y] = true;
            q.pop();

            for (auto& [x, w, i] : g[y]) {
                if (dis[x] + w != dis[y]) {
                    continue;
                }

                ans[i] = true;
                if (!vis[x]) {
                    q.emplace(x);
                }
            }
        }

        return ans;
    }
};