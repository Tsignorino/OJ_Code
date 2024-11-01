#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> row(n + 1, pair(INT_MAX / 2, 0));
    vector<pair<int, int>> col(n + 1, pair(INT_MAX / 2, 0));
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;

        row[u] = pair(min(row[u].first, v), max(row[u].second, v));
        col[v] = pair(min(col[v].first, u), max(col[v].second, u));
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, row[i].second - row[i].first);
        ans = max(ans, col[i].second - col[i].first);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}