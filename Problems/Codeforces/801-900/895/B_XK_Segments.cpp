#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, x, k;
    cin >> n >> x >> k;

    vector<ll> vec(n);
    for (ll& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    ll ans = 0;
    for (ll& v : vec) {
        ll l = (v - 1) / x + k;
        ans += ranges::lower_bound(vec, (l + 1) * x) - ranges::lower_bound(vec, max(v, l * x));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}