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

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    ll ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (vec[i] == cnt) {
            ans++;
            continue;
        }
        ll d = (vec[i] - cnt) * 1ll * (n - i);
        if (d >= k) {
            ans += k;
            break;
        }
        cnt = vec[i];
        ans += d + 1;
        k -= d;
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