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

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp[v]++;
    }

    int ans = 0;
    for (auto& [_, c] : mp) {
        ans += c / 3;
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