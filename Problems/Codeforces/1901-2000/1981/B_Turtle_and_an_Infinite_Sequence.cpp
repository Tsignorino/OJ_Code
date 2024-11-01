#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    // m 秒后的 a[n]

    if (m == 0) {
        cout << n << "\n";
        return;
    }

    int l = max(n - m, 0), r = n + m;
    ll ans = 0;
    for (int i = __lg(r) + 1; i >= 0; --i) {
        if ((l >> i & 1) == (r >> i & 1)) {
            ans |= (l >> i & 1) << i;
        } else {
            ans |= (1 << (i + 1)) - 1;
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
