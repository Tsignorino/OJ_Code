#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g0(n), g1(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        u--, v--;
        g0[u].emplace_back(v, w);
        g1[v].emplace_back(u, w);
    }

    vector<ll> f(n, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [d, x] = q.top();
        q.pop();

        if (f[x] != -1) {
            continue;
        }

        f[x] = d;
        for (auto [y, v] : g0[x]) {
            q.emplace(d + v, y);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (f[i] != -1) {
            q.emplace(f[i], i);
        }
    }

    f.assign(n, -1);
    while (!q.empty()) {
        auto [d, x] = q.top();
        q.pop();

        if (f[x] != -1) {
            continue;
        }

        f[x] = d;
        for (auto [y, v] : g1[x]) {
            q.emplace(d + v, y);
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << f[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
