#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    ll ans = n * 1ll * (n + 1) / 2;
    vector<int> f(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        int id = ranges::lower_bound(pre, pre[i] + x + 1) - pre.begin();
        f[i] = (id == n + 1 ? 0 : f[id] + 1);
        ans -= f[i];
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