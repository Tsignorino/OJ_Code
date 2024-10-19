#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
    }

    vector<int> vis(n);
    vis[0] = 1;

    queue<pair<int, int>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [u, cnt] = q.front();
        q.pop();

        for (int& v : g[u]) {
            if (v == 0) {
                cout << cnt << "\n";
                return;
            }
            if (vis[v]) {
                continue;
            }
            vis[v] = 1;
            q.emplace(v, cnt + 1);
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}