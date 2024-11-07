#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<ll> c(n + 1), s(n + 1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        ans += c[v] * (i - 1) - s[v];
        ans -= c[v] * (c[v] - 1) / 2;
        c[v]++;
        s[v] += i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}