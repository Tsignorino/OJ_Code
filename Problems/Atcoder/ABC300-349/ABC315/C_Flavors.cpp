// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        int f, t;
        cin >> f >> t;
        mp[f].emplace_back(t);
    }

    int ans = 0;
    int mx1 = 0, mx2 = 0;
    for (auto& [_, v] : mp) {
        int m = v.size();
        ranges::sort(v);
        if (v.size() > 1) {
            ans = max(ans, v[m - 1] + v[m - 2] / 2);
        }
        if (v[m - 1] > mx1) {
            mx2 = mx1;
            mx1 = v[m - 1];
        } else if (v[m - 1] > mx2) {
            mx2 = v[m - 1];
        }
    }
    cout << max(ans, mx1 + mx2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}