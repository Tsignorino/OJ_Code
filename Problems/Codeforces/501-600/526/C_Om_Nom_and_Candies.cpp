#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    ll c, h1, h2, w1, w2;
    cin >> c >> h1 >> h2 >> w1 >> w2;

    ll ans = 0;
    for (int i = 0; i <= 1e5; ++i) {
        if (w1 * i > c) {
            break;
        }
        ans = max(ans, h1 * i + (c - i * w1) / w2 * h2);
    }
    for (int i = 0; i <= 1e5; ++i) {
        if (w2 * i > c) {
            break;
        }
        ans = max(ans, h2 * i + (c - i * w2) / w1 * h1);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
