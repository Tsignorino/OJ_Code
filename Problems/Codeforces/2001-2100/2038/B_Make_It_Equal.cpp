// Date: 2024-11-28  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    ll sum = accumulate(a.begin(), a.end(), 0ll);

    auto check = [&](auto x) {
        vector<int> b(a);
        for (int k = 0; k < 50; ++k) { // unreasonable data
            for (int i = 0; i < n; ++i) {
                if (b[i] > x) {
                    b[(i + 1) % n] += (b[i] - x) / 2;
                    b[i] -= (b[i] - x) / 2 * 2;
                }
            }
        }
        return b == vector<int>(n, b[0]);
    };

    int lo = 0, hi = sum / n + 1;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;

        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    if (lo == 0) {
        cout << -1 << "\n";
    } else {
        cout << sum - n * 1ll * lo << "\n";
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