#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int x, y, t;
    cin >> x >> y >> t;

    if (y < x) { // 先碰到钥匙
        cout << x << "\n";
    } else { // 先碰到宝箱
        cout << y * 2 - min(x + t, y) << "\n";
    }
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