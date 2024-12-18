// Date: 2024-12-18  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (auto& [u, v] : a) {
        cin >> u >> v;
    }

    ranges::sort(a, [&](const auto& p, const auto& q) { return p.first < q.first || p.first == q.first && p.second < q.second; });

    // debug(a);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ans <= a[i].second) {
            ans = a[i].second;
        } else {
            ans = a[i].first;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}