#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& vec : times) {
            int u = vec[0], v = vec[1], w = vec[2];
            g[u].emplace_back(v, w);
        }

        // 堆优化 稀疏图
        vector<ll> dis(n + 1, LLONG_MAX / 2);
        auto dijkstra = [&](int s = 0) {
            dis[s] = 0;

            using PLL = pair<ll, ll>;
            priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
            pq.emplace(0, s); // dis[k], k
            while (!pq.empty()) {
                auto [d, cur] = pq.top();
                pq.pop();

                if (d > dis[cur]) {
                    continue;
                }
                for (auto& [to, w] : g[cur]) {
                    if (dis[to] > d + w) {
                        dis[to] = d + w;
                        pq.emplace(dis[to], to);
                    }
                }
            }
            return 0;
        };
        // The node-index starts from 0

        dijkstra(k);

        auto ans = *max_element(dis.begin() + 1, dis.end());
        if (ans == LLONG_MAX / 2) {
            ans = -1;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}