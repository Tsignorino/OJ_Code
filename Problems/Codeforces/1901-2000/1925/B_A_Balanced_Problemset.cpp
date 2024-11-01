#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int x, n;
    cin >> x >> n;

    if (x % n == 0) {
        cout << x / n << "\n";
        return;
    }

    int ans = 1;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) { // 枚举所有因数
            if (n <= x / i) {
                ans = max(ans, i);
            }
            if (n <= i) {
                ans = max(ans, x / i);
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
