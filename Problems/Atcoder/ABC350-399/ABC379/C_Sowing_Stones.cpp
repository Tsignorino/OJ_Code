#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> vec(m);
    for (auto& [v, _] : vec) {
        cin >> v;
    }
    for (auto& [_, v] : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    /*
        考虑棋子所在单元格的下标总和，每移动一次就增加 1。
        最终总和减去当前总和就是移动次数。
    */

    ll ans = n * 1ll * (n + 1) / 2;
    ll sum = 0;
    for (auto& [v, c] : vec) {
        if (sum < v - 1) {
            cout << -1 << "\n";
            return;
        }
        ans -= v * 1ll * c;
        sum += c;
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