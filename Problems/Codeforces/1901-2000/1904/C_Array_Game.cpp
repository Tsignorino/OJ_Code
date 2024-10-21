#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> vec(n);
    for (auto& v : vec) {
        cin >> v;
    }

    if (k >= 3) {
        cout << 0 << "\n";
        return;
    }

    ranges::sort(vec);

    ll ans = ranges::min(vec);
    for (int i = 1; i < n; ++i) {
        ans = min(ans, vec[i] - vec[i - 1]);
    }
    if (k == 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ll d = vec[j] - vec[i];

                auto iter = ranges::lower_bound(vec, d);
                ans = min(ans, *iter - d);
                if (iter != vec.begin()) {
                    ans = min(ans, d - *prev(iter));
                }
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