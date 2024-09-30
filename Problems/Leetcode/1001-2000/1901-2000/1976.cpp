#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
    struct edge {
        int to, w;
    };

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // dijkstra
        vector<vector<edge>> adj(n + 1);
        for (vector<int>& v : roads) {
            adj[v[0] + 1].emplace_back(v[1] + 1, v[2]);
            adj[v[1] + 1].emplace_back(v[0] + 1, v[2]);
        }

        vector<i64> dis(n + 1, LLONG_MAX / 2);
        vector<int> dp(n + 1), vis(n + 1);
        dp[1] = 1;

        auto plain_dijkstra = [&](int s) -> void {
            for (int i = 1; i < n; ++i) {
                int cur = 0;
                for (int j = 1; j <= n; ++j) {
                    if (vis[j] == 0 && dis[j] < dis[cur]) {
                        cur = j;
                    }
                }
                vis[cur] = 1;

                for (auto& [to, w] : adj[cur]) {
                    i64 val = dis[cur] + w;
                    if (dis[to] > val) {
                        dis[to] = val;
                        dp[to] = dp[cur];
                    } else if (dis[to] == val) {
                        dp[to] = (dp[to] + dp[cur]) % 1'000'000'007;
                    }
                }
            }
        };
        dis[1] = 0;
        plain_dijkstra(1);

        return dp[n];
    }
};
