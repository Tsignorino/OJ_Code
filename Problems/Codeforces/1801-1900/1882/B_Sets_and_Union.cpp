#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> vec(n);
    ll or_ = 0;
    for (int i = 0; i < n; ++i) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int k;
            cin >> k;
            vec[i] |= 1ll << (k - 1);
        }
        or_ |= vec[i];
    }

    int ans = 0;
    while (or_ > 0) {
        ll lowbit = or_ & -or_;
        ll res = 0;
        for (ll& v : vec) {
            if ((v & lowbit) == 0) {
                res |= v;
            }
        }
        ans = max(ans, __builtin_popcountll(res));

        or_ ^= lowbit;
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