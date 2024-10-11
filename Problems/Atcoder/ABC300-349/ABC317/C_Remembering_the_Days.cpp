#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        g[u][v] = g[v][u] = w;
    }

    vector<int> vis(n);
    int ans = 0;
    auto dfs = [&](auto&& dfs, int x, int sum) -> void {
        vis[x] = 1;
        ans = max(ans, sum);
        for (int y = 0; y < n; ++y) {
            if (g[x][y] != -1 && vis[y] == 0) {
                dfs(dfs, y, sum + g[x][y]);
            }
        }
        vis[x] = 0;
    };

    for (int i = 0; i < n; ++i) {
        dfs(dfs, i, 0);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}