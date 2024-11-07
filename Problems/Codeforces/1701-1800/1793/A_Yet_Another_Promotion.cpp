#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    cin >> a >> b;

    int n, m;
    cin >> n >> m;

    ll ans = 0;
    if (m * 1ll * a >= (m + 1) * 1ll * b) {
        ans = n * 1ll * b;
    } else {
        ans = n / (m + 1) * 1ll * m * a + n % (m + 1) * 1ll * min(a, b);
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