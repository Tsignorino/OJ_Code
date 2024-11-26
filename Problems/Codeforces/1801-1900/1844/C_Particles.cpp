// Date: 2024-11-26  星期二

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

    vector<ll> a(n);
    for (auto& v : a) {
        cin >> v;
    }

    /*
        贪心
    */
    ll odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        (i & 1 ? even : odd) += max(a[i], 0ll);
    }

    ll ans = max(odd, even);

    /*
        DP
    */
    // ll mx = numeric_limits<ll>::min();
    // vector<ll> dp(n + 2);
    // for (int i = 0; i < n; ++i) {
    //     dp[i + 2] = max(max(dp[i], a[i]), dp[i] + a[i]);
    // }
    //
    // ll ans = ranges::max(dp);

    if (ll val = ranges::max(a); val < 0) {
        ans = val;
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