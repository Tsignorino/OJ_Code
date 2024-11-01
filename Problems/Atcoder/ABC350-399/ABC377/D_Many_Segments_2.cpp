#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> f(m, m);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        f[l] = min(f[l], r);
    }
    for (int i = m - 2; i >= 0; --i) {
        f[i] = min(f[i], f[i + 1]);
    }

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += f[i] - i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}