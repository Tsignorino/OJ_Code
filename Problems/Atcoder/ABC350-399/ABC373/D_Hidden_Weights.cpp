#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, -w);
    }

    vector<ll> dis(n, 0);
    vector<int> vis(n);

    auto dfs = [&](auto self, int v) -> void {
        vis[v] = 1;
        for (auto [u, w] : g[v]) {
            if (vis[u] == 0) {
                dis[u] = dis[v] + w;
                self(self, u);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            dfs(dfs, i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dis[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}