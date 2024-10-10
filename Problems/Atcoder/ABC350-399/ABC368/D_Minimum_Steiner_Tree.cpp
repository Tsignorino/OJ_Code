#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> f(n);
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        v--;
        f[v] = 1;
    }

    vector<int> sum(n);
    int ans = 0;
    auto dfs = [&](auto&& dfs, int x = 0, int p = -1) -> void {
        sum[x] = f[x];

        int res = 0;
        if (f[x] == 1) {
            res += 2;
        }
        for (int y : g[x]) {
            if (y == p) {
                continue;
            }
            dfs(dfs, y, x);
            sum[x] += sum[y];
            if (sum[y] > 0) {
                res++;
            }
        }
        if (sum[x] < k) {
            res++;
        }
        if (res >= 2) {
            ans++;
        }
    };
    dfs(dfs);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}