#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

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
