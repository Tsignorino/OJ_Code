#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int S = n * 2;
        int T = S + 1;

        struct neighbor {
            int to, rid, cap, cost;
        };
        vector<vector<neighbor>> g(T + 1);
        auto addEdge = [&](int from, int to, int cap, int cost) {
            g[from].emplace_back(to, ssize(g[to]), cap, cost);
            g[to].emplace_back(from, ssize(g[from]) - 1, 0, -cost);
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = 1 + k * j;
                addEdge(i, n + j, 1, (strength[i] - 1) / x + 1);
            }
            addEdge(S, i, 1, 0);
        }
        for (int i = n; i < S; ++i) {
            addEdge(i, T, 1, 0);
        }

        // template
        vector<pair<int, int>> pa(T + 1); // int v, i;
        vector<int> dis(T + 1), inQ(T + 1);
        auto spfa = [&]() {
            fill(dis.begin(), dis.end(), numeric_limits<int>::max());
            dis[S] = 0, inQ[S] = 1;
            queue<int> q;
            q.emplace(S);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                inQ[v] = 0;
                for (int i = 0; i < g[v].size(); ++i) {
                    if (g[v][i].cap == 0) {
                        continue;
                    }
                    int w = g[v][i].to;
                    int nd = dis[v] + g[v][i].cost;
                    if (nd < dis[w]) {
                        dis[w] = nd;
                        pa[w] = {v, i};
                        if (inQ[w] == 0) {
                            inQ[w] = 1;
                            q.emplace(w);
                        }
                    }
                }
            }
            return dis[T] < numeric_limits<int>::max();
        };

        int minCost = 0;
        while (spfa()) {
            int minF = numeric_limits<int>::max();
            for (int v = T; v != S;) {
                auto& [pv, pi] = pa[v];
                minF = min(minF, g[pv][pi].cap);
                v = pv;
            }
            for (int v = T; v != S;) {
                auto& [pv, pi] = pa[v];
                auto& e = g[pv][pi];
                e.cap -= minF;
                g[v][e.rid].cap += minF;
                v = pv;
            }
            minCost += dis[T] * minF;
        }
        return minCost;
    }
};

int main() {
    Solution sol;

    return 0;
}