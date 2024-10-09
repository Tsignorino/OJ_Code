#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int x, y;
    cin >> x >> y;

    cout << max((y + 1) / 2, (x + y * 4 + 14) / 15) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
