#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> vec(m);
    for (int i = 0; i < m; i++) {
        cin >> vec[i].first;
    }
    for (int i = 0; i < m; i++) {
        cin >> vec[i].second;
    }

    ranges::sort(vec);

    /*
        考虑棋子所在单元格的指数总和，每移动一次 sum 就增加 1
    */

    ll ans = n * (n + 1) / 2;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        if (sum < vec[i].first - 1) {
            cout << -1 << "\n";
            return;
        }
        ans -= vec[i].first * vec[i].second;
        sum += vec[i].second;
    }
    if (sum != n) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}