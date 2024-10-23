#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp[v % k].push_back(v / k);
    }

    ll ans = 0;
    int ok = 0;
    for (auto& [_, a] : mp) {
        ranges::sort(a);

        int m = a.size();
        ll s = 0;
        for (int i = m - 2; i >= 0; i -= 2) { // skill-1
            s += a[i + 1] - a[i];
        }
        if (m % 2 == 0) {
            ans += s;
            continue;
        }
        if (ok) {
            ans = -1;
            break;
        }
        ok = 1;

        ll mn = s;
        for (int i = 1; i < m; i += 2) {
            s += a[i] - a[i - 1] - (a[i + 1] - a[i]); // skill-2
            mn = min(mn, s);
        }
        ans += mn;
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