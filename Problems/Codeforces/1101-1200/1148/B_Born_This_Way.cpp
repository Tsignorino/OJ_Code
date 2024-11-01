#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    if (k >= n) {
        cout << -1 << "\n";
        return;
    }

    ll ans = 0;
    for (int i = 0; i <= k; ++i) { // WA
        int idx = ranges::lower_bound(b, a[i] + ta) - b.begin() + k - i;
        if (idx >= m) {
            cout << -1 << "\n";
            return;
        }
        ans = max(ans, b[idx] * 1ll);
    }
    cout << ans + tb << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}