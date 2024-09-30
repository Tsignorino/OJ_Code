#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 右边界应该是 x + a[i]
    int l = 0, r = 2e9 + 7;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        ll w = 0;
        for (int i = 0; i < n; ++i) {
            w += max(0LL, mid * 1LL - a[i]);
        }

        if (w <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << "\n";
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
