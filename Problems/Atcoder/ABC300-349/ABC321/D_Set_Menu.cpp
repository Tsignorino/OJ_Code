#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> s(n), t(m);
    for (int& v : s) {
        cin >> v;
    }
    for (int& v : t) {
        cin >> v;
    }

    ranges::sort(s);
    ranges::sort(t);

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + s[i];
    }

    // debug(s);
    // debug(t);
    // debug(pre);

    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        int cnt = ranges::lower_bound(s, p - t[i]) - s.begin();
        ans += pre[cnt] + t[i] * 1ll * cnt + p * 1ll * (n - cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}