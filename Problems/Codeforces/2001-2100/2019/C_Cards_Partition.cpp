#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> vec(n);
    for (ll& v : vec) {
        cin >> v;
    }

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);
    ll mx = ranges::max(vec);

    for (int i = n; i >= 1; --i) {
        ll m = (sum + k) / i;
        if (m >= mx && sum <= m * i) {
            cout << i << "\n";
            return;
        }
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