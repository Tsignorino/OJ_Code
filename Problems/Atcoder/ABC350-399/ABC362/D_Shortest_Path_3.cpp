#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge {
    int to;
    ll w;
};

void solve() {
    int n, m; // 点的个数，有向边个数
    cin >> n >> m;

    vector adj(n + 1, vector<edge>());
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<ll> dis(n + 1, LLONG_MAX / 2);
    dis[1] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    using PLI = pair<ll, int>;
    priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
    pq.emplace(0, 1); // dis[k], k
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        if (d > dis[cur]) {
            continue;
        }
        for (auto& [to, w] : adj[cur]) {
            if (dis[to] > d + w + p[to]) {
                dis[to] = d + w + p[to];
                pq.emplace(dis[to], to);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] + p[1] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
