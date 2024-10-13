#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector dis(n, vector<ll>(k + 1, LLONG_MAX));
    vector st(n, vector<ll>(k + 1));

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> q;
    dis[0][0] = vec[0];
    q.emplace(vec[0], 0, 0);
    if (k != 0) {
        dis[0][1] = 1;
        q.emplace(1, 0, 1);
    }
    while (!q.empty()) {
        auto [w, x, i] = q.top();
        q.pop();

        if (st[x][i] == 1) {
            continue;
        }
        st[x][i] = 1;

        for (int y : g[x]) {
            if (dis[y][0] > vec[y] + w) { // 休息
                dis[y][0] = vec[y] + w;
                q.emplace(dis[y][0], y, 0);
            }
            if (i + 1 <= k && dis[y][i + 1] > w + 1) { // 不休息
                dis[y][i + 1] = w + 1;
                q.emplace(dis[y][i + 1], y, i + 1);
            }
        }
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dis[n - 1][i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}