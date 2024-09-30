#include <bits/stdc++.h>

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

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    ll mx = 0, mn = numeric_limits<ll>::max(); // 最大斜率、最小斜率
    for (int i = 0; i <= n; ++i) {
        ll l = pre[i], r = pre[n] - pre[i];

        if (i < n) {
            mx = max(mx, (r + n - 1 - i) / (n - i));
        }
        if (i > 0) {
            mn = min(mn, l / i);
        }
    }
    cout << mx - mn << "\n";
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