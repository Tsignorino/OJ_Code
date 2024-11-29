// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int h;
    ll n;
    cin >> h >> n;

    auto dfs = [&](this auto&& dfs, ll l, ll r, int cur, int d) -> ll {
        if (d == 0) {
            return 0;
        }
        ll m = l + (r - l) / 2;
        ll ans = (n <= m) == cur ? 1ll << d : 1;
        ans += n <= m ? dfs(l, m, 1, d - 1) : dfs(m + 1, r, 0, d - 1);
        return ans;
    };
    cout << dfs(1, 1ll << h, 0, h) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}