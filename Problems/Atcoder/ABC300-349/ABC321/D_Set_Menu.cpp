#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

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

    ranges::sort(t);

    vector<ll> pre(m + 1);
    for (int i = 0; i < m; ++i) {
        pre[i + 1] = pre[i] + t[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = ranges::lower_bound(t, p - s[i]) - t.begin();
        ans += pre[cnt] + s[i] * 1ll * cnt + p * 1ll * (m - cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}