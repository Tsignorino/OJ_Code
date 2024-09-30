#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i && a[i - 1] > a[i]) {
            ans = max(ans, a[i - 1]);
        }
    }

    // int r = n - 1;
    // for (; r > -1 && a[r] >= a[r - 1]; --r) {}
    // int ans = 0;
    // for (int i = 0; i < r; ++i) {
    //     ans = max(ans, a[i]);
    // }

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
