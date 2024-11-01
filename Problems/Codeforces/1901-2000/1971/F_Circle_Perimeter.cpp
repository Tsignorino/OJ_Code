#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int d;
    cin >> d;

    auto calc = [&](ll d) { // 外轮廓以内包含多少个点
        ll res = 0;
        for (ll x = -d; x <= d; ++x) {
            ll l = ceil(sqrt((d + 1) * (d + 1) - x * x)) - 1;
            // ll l = -1, r = d + 1;
            // while (l + 1 < r) {
            //     ll mid = l + (r - l) / 2;
            //     (mid * mid + x * x < (d + 1) * (d + 1) ? l : r) = mid;
            // }
            res += 2 * l + 1;
        }
        return res;
    };
    cout << calc(d) - calc(d - 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
