#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> vec(n);
    for (ll& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    ll ans = 0;
    ll sum = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        sum += vec[r];
        while (l < r && vec[r] - vec[l] > 1) {
            sum -= vec[l++];
        }
        while (sum > m) {
            sum -= vec[l++];
        }
        ans = max(ans, sum);
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