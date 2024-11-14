#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<int> f(m + 1);
    for (int i = 1, j = 0; i <= m; ++i) {
        while (j <= n && pre[j] - pre[f[i - 1]] < v) {
            j++;
        }
        f[i] = j;
    }

    vector<int> g(m + 1);
    g[0] = n;
    for (int i = 1, j = n; i <= m; ++i) {
        while (j >= 0 && pre[g[i - 1]] - pre[j] < v) {
            j--;
        }
        g[i] = j;
    }

    ll ans = -1;
    for (int i = 0; i <= m; ++i) {
        if (f[i] <= g[m - i]) {
            ans = max(ans, pre[g[m - i]] - pre[f[i]]);
        }
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