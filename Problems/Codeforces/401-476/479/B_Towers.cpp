// Date: 2024-12-18  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    multiset<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        s.emplace(v, i + 1);
    }

    vector<pair<int, int>> ans;
    while (k-- && s.rbegin()->first - s.begin()->first >= 2) {
        auto [v1, idx1] = *s.rbegin();
        auto [v2, idx2] = *s.begin();
        s.extract({v1, idx1});
        s.extract({v2, idx2});
        s.emplace(v1 - 1, idx1);
        s.emplace(v2 + 1, idx2);
        ans.emplace_back(idx1, idx2);
    }

    cout << s.rbegin()->first - s.begin()->first << " " << ans.size() << "\n";
    for (auto& [u, v] : ans) {
        cout << u << " " << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}