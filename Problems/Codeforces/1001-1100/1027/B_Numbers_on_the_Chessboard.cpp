#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int x, y;
        cin >> x >> y;

        ll ans = ((x - 1) * 1ll * n + y + 1) / 2;
        if ((x + y) % 2) {
            ans += (n * 1ll * n + 1) / 2;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}