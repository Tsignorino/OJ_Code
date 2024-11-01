#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Node {
    int v, x, y;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<Node>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--, v--;

        g[u].emplace_back(v, x, y);
        g[v].emplace_back(u, -x, -y);
    }

    vector<pair<ll, ll>> ans(n);
    ans[0] = {0, 0};

    vector<int> vis(n);
    vis[0] = 1;
    auto dfs = [&](auto&& dfs, int u) -> void {
        for (auto& [v, x, y] : g[u]) {
            if (vis[v] == 1) {
                continue;
            }
            vis[v] = 1;
            ans[v] = {ans[u].first + x, ans[u].second + y};
            dfs(dfs, v);
        }
    };

    dfs(dfs, 0);

    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            cout << "undecidable\n";
        } else {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}