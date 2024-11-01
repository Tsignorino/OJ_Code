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

    vector<ll> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }

    ll ans = 1e18;
    if (n % 2 == 0) {
        ll res = 0;
        for (int i = 0; i < n; i += 2) {
            res = max(res, vec[i + 1] - vec[i]);
        }
        ans = min(ans, res);
    } else {
        for (int i = 0; i < n; ++i) {
            ll res = 0;
            for (int j = 0; j < n; j += 2) {
                if (i == j) {
                    j--;
                    continue;
                }
                res = max(res, vec[j + 1] - vec[j]);
            }
            ans = min(ans, res);
        }
    }
    cout << max(ans, 1ll) << "\n";
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